#include "entity.h"

Entity::Entity() {
}

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

void Entity::update(sf::Vector2f direction) {

}

void Entity::render(sf::RenderWindow& window) {
}
