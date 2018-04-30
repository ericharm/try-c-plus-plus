#include "hero.h"

using std::cout;

Hero::Hero(SceneNode::TextureHolder& textures) {
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

void Hero::updateCurrent(sf::Time dt) {
  float speed = 100.0;
  sf::Vector2f v = getVelocity();
  if (isMovingUp) { v.y = speed * (-1.f); }
  if (isMovingDown) { v.y = speed * (1.f); }
  if (isMovingLeft) { v.x = speed * (-1.f); }
  if (isMovingRight) { v.x = speed * (1.f); }
  setVelocity(v);
  move(v * dt.asSeconds());
  setVelocity(0.0, 0.0);
  isMovingUp = false; isMovingDown = false;
  isMovingLeft = false; isMovingRight = false;
}

unsigned int Hero::getCategory() const {
  return Category::Hero;
}

void Hero::setMoving(Direction direction) {
  switch(direction) {
    case Up : isMovingUp = true; break;
    case Down : isMovingDown = true; break;
    case Left : isMovingLeft = true; break;
    case Right : isMovingRight = true; break;
  }
}
