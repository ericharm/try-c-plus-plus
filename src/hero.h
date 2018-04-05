#ifndef HERO_H
#define HERO_H

#include <SFML/Graphics.hpp>

#include "textures.cpp"
#include "entity.h"

class Hero : public Entity {

  public:
    Hero(TextureHolder& textures);

  private:
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

  private:
    sf::Texture texture;
    sf::Sprite sprite;

};
#endif
