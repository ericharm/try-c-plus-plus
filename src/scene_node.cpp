#include "scene_node.h"

#include <iostream>
#include <algorithm>
#include <cassert>

SceneNode::SceneNode() : children(), parent(nullptr) {
}

void SceneNode::attachChild(NodePtr child) {
  child->parent = this;
  children.push_back(std::move(child));
}

SceneNode::NodePtr SceneNode::detachChild(const SceneNode& child) {
  auto found = std::find_if(children.begin(), children.end(), 
      [&] (NodePtr& p) -> bool { return p.get() == &child; }); 
  assert(found != children.end());

  NodePtr result = std::move(*found);
  result->parent = nullptr;
  children.erase(found);
  return result;
}

void SceneNode::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  states.transform *= getTransform();
  drawCurrent(target, states);
  drawChildren(target, states);
}

void SceneNode::update(sf::Time dt) {
  updateCurrent(dt);
  updateChildren(dt);
}

void SceneNode::drawChildren(sf::RenderTarget& target, sf::RenderStates states) const {
  for (const NodePtr& child : children) {
    child->draw(target, states);
  }
}

void SceneNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const {
}

void SceneNode::updateChildren(sf::Time dt) const {
  for (const NodePtr& child : children) {
    child->update(dt);
  }
}

void SceneNode::updateCurrent(sf::Time dt) {
}

sf::Transform SceneNode::getWorldTransform() const {
  sf::Transform transform = sf::Transform::Identity;
  for (const SceneNode* node = this; node != nullptr; node = node->parent) {
    transform = node->getTransform() * transform;
  }
  return transform;
}

sf::Vector2f SceneNode::getWorldPosition() const {
  return getWorldTransform() * sf::Vector2f();
}
