#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "world.h"

class Game {

  public:
    Game();
    void run();

  private:
    void handleInput();
    void update(sf::Time deltaTime);
    void draw();

  private:
    sf::RenderWindow window;
    World world;

};
#endif
