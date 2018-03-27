#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "textures.cpp"
#include "resource_holder.cpp"
#include "hero.h"

class Game {

  public:
    typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;
    Game(TextureHolder* textures);
    void run();

  private:
    void handleInput();
    void update(sf::Time deltaTime);
    void render();

    void handleKeyPress(sf::Keyboard::Key key, bool isPressed);

  private:
    sf::RenderWindow window;
    std::vector<Hero> entities;
    TextureHolder* textures;

    bool movingUp;
    bool movingDown;
    bool movingLeft;
    bool movingRight;
};
#endif
