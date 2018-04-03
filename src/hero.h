#ifndef HERO_H
#define HERO_H
#include "game.h"
#include "textures.cpp"
#include "entity.h"
#include <SFML/Graphics.hpp>

class Hero : public Entity {

  public:
    // can't use Game::TextureHolder just yet because it
    // creates a circular dependency
    typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;
    Hero(TextureHolder& textures);

  private:
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

  private:
    sf::Texture texture;
    sf::Sprite sprite;

};
#endif
