#include "hero.h"

using namespace std;

Hero::Hero(sf::Texture texture) {
  this->texture = texture;
  this->sprite = sf::Sprite(this->texture);
  this->sprite.setPosition(10.f, 10.f);
}

void Hero::update(sf::Vector2f movement) {
  float speed = 1;
  this->sprite.move(movement);
}

void Hero::render(sf::RenderWindow &window) {
    this->sprite.setTexture(this->texture);
    window.draw(this->sprite);
}
