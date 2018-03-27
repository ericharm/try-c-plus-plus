#ifndef HERO_H
#define HERO_H
#include "textures.cpp"
#include "entity.h"
#include <SFML/Graphics.hpp>

class Hero : public Entity {

  public:
    typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;
    Hero(TextureHolder& textures);
    virtual void update(sf::Vector2f direction);
    virtual void render(sf::RenderWindow& window);

  private:
    sf::Texture texture;
    sf::Sprite sprite;

};
#endif
