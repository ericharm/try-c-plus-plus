#include "hero.h"

Hero::Hero(TextureHolder& textures) {
  texture = textures.get(Textures::Hero);
  sprite = sf::Sprite(texture);
  sprite.setTexture(texture);
  sprite.setPosition(10.f, 10.f);
  setVelocity(1.0, 1.0);

  sf::FloatRect bounds = sprite.getLocalBounds();
  sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void Hero::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(sprite, states);
}
