#include <SFML/Graphics.hpp>
#include "hero.h"

using namespace std;

Hero::Hero() {
  this->shape = sf::CircleShape(100.f);
  this->shape.setRadius(10.f);
  this->shape.setPosition(10.f, 10.f);
  this->shape.setFillColor(sf::Color::Red);
}

void Hero::update(sf::Vector2f movement) {
  float speed = 1;
  this->shape.move(movement);
}

void Hero::render(sf::RenderWindow &window) {
    window.draw(this->shape);
}
