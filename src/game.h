#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "hero.h"

using namespace std;

class Game {

  public:
    Game();
    void run();

  private:
    void handleInput();
    void update(sf::Time);
    void render();

    void handleKeyPress(sf::Keyboard::Key, bool);

  private:
    sf::RenderWindow window;
    Hero hero;

    bool movingUp;
    bool movingDown;
    bool movingLeft;
    bool movingRight;

};
#endif
