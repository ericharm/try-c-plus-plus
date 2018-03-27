#include "hero.h"

Hero::Hero(TextureHolder& textures) {
  texture = textures.get(Textures::Hero);
  sprite = sf::Sprite(texture);
  sprite.setPosition(10.f, 10.f);
}

void Hero::update(sf::Vector2f movement) {
  float speed = 1;
  sprite.move(movement);
}

void Hero::render(sf::RenderWindow &window) {
  sprite.setTexture(texture);
  window.draw(sprite);
}
