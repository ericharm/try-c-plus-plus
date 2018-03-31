#include "entity.h"

void Entity::setVelocity(sf::Vector2f velocity) {
  this->velocity = velocity;
}

void Entity::setVelocity(float x, float y) {
  this->velocity.x = x;
  this->velocity.y = y;
}

sf::Vector2f Entity::getVelocity() const {
  return this->velocity;
}

// these custom update and render functions will soon be gone
void Entity::updatex(sf::Vector2f direction) {
}

void Entity::updateCurrent(sf::Time dt) {
  move(velocity * dt.asSeconds());
}
