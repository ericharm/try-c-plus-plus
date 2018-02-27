#include <SFML/Graphics.hpp>
#include "hero.h"

using namespace std;

Hero::Hero() {
  this->texture = sf::Texture();
  if (!texture.loadFromFile("assets/images/hero.png")) {
    throw "FileNotFound";
  }
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
