#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "entity.h"

class Game {

  public:
    Game();
    void run();

  private:
    void handleInput();
    void update(sf::Time deltaTime);
    void draw();
    void handleKeyPress(sf::Keyboard::Key key, bool isPressed);

  private:
    sf::RenderWindow window;
    std::vector<Entity*> entities;

    bool movingUp;
    bool movingDown;
    bool movingLeft;
    bool movingRight;
};
#endif
