#include "sprite_node.h"

SpriteNode::SpriteNode(sf::Texture& texture) : sprite(texture) {
}

SpriteNode::SpriteNode(sf::Texture& texture, sf::IntRect& textureRect)
: sprite(texture, textureRect) {
}

void SpriteNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(sprite, states);
}
