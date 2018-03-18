#ifndef HERO_H
#define HERO_H
#include <SFML/Graphics.hpp>

class Hero {

  public:
    Hero();
    void update(sf::Vector2f direction);
    void render(sf::RenderWindow& window);

  private:
    sf::Texture texture;
    sf::Sprite sprite;

};
#endif
