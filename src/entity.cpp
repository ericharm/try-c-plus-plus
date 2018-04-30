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
  move(velocity * dt.asSeconds());
}

void Entity::accelerate(sf::Vector2f v) {
  velocity += v;
}

void Entity::accelerate(float x, float y) {
  velocity += sf::Vector2f(x, y);
}
