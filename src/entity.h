#ifndef ENTITY_H
#define ENTITY_H
#include "scene_node.h"
#include <SFML/Graphics.hpp>

class Entity : public SceneNode {

  public:
    void setVelocity(sf::Vector2f velocity);
    void setVelocity(float x, float y);
    void accelerate(sf::Vector2f velocity);
    void accelerate(float x, float y);
    sf::Vector2f getVelocity() const;

  private:
    void updateCurrent(sf::Time dt);

  private:
    sf::Vector2f velocity;
};
#endif
