#ifndef SCENE_NODE_H
#define SCENE_NODE_H

#include <vector>
#include <memory>
#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable {
  public:
    typedef std::unique_ptr<SceneNode> NodePtr;
    SceneNode();
    void attachChild(NodePtr child);
    NodePtr detachChild(const SceneNode& child);
    void update(sf::Time dt);
    sf::Transform getWorldTransform() const;
    sf::Vector2f getWorldPosition() const;

  private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void updateCurrent(sf::Time dt) const;
    void updateChildren(sf::Time dt) const;

  private:
    std::vector<NodePtr> children;
    SceneNode* parent;
};
#endif
