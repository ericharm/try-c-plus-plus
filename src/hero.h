#ifndef HERO_H
#define HERO_H

#include <SFML/Graphics.hpp>
#include "textures.cpp"
#include "entity.h"
#include "direction.cpp"

class Hero : public Entity {

  public:
    Hero(TextureHolder& textures);
    virtual unsigned int getCategory() const;
    void setMoving(Direction);

  private:
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void updateCurrent(sf::Time);

  private:
    sf::Texture texture;
    sf::Sprite sprite;
    bool isMovingUp;
    bool isMovingDown;
    bool isMovingLeft;
    bool isMovingRight;

};
#endif
