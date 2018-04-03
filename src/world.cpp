#include "world.h"

World::World(sf::RenderWindow& w) : window(w) {
  // sceneGraph = 
}

void World::update(sf::Time deltaTime) {
  // std::cout << "Updating world" << std::endl;
}

void World::draw() {
  window.draw(sceneGraph);
  // for (SceneNode* layer : layers) {
    // entity->setVelocity(movement);
    // layer->draw(deltaTime);
  // }
  // std::cout << "Drawing world" << std::endl;
}
