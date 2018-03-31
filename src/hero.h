#ifndef HERO_H
#define HERO_H
#include "textures.cpp"
#include "entity.h"
#include <SFML/Graphics.hpp>

class Hero : public Entity {

  public:
    typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;
    Hero(TextureHolder& textures);
    virtual void updatex(sf::Vector2f direction);

  private:
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

  private:
    sf::Texture texture;
    sf::Sprite sprite;

};
#endif
