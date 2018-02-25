#ifndef HERO_H
#define HERO_H
#include <SFML/Graphics.hpp>

using namespace std;

class Hero {

  public:
    Hero();
    void update(sf::Vector2f);
    void render(sf::RenderWindow&);

  private:
    sf::CircleShape shape;

};
#endif
