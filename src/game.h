#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "textures.cpp"
// interesting this causes a linker error when trying to include
// the header instead?
#include "resource_holder.cpp"
#include "hero.h"

class Game {

  public:
    Game(ResourceHolder<sf::Texture, Textures::ID>* textures);
    void run();

  private:
    void handleInput();
    void update(sf::Time deltaTime);
    void render();

    void handleKeyPress(sf::Keyboard::Key key, bool isPressed);

  private:
    sf::RenderWindow window;
    std::vector<Hero> entities;
    ResourceHolder<sf::Texture, Textures::ID>* textures;

    bool movingUp;
    bool movingDown;
    bool movingLeft;
    bool movingRight;
};
#endif
