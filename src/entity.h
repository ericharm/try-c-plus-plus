#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>

class Entity {

  public:
    void setVelocity(sf::Vector2f velocity);
    void setVelocity(float x, float y);
    sf::Vector2f getVelocity() const;
  private:
    sf::Vector2f velocity;
};
#endif
