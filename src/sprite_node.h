#ifndef SPRITE_NODE_H
#define SPRITE_NODE_H
#include "scene_node.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics.hpp>

class SpriteNode : public SceneNode {

  public:
    SpriteNode(sf::Texture& texture);
    SpriteNode(sf::Texture& texture, sf::IntRect& textureRect);

  private:
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

  private:
    sf::Sprite sprite;
};
#endif
