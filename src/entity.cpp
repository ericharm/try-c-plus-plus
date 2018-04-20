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

void Entity::updateCurrent(sf::Time dt) {
  move(getVelocity() * dt.asSeconds());
}

void Entity::accelerate(sf::Vector2f v) {
  velocity += v;
}
