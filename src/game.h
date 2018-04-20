#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "world.h"
#include "game_input_handler.h"

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
    GameInputHandler inputHandler;

};
#endif
