#include <SFML/Graphics.hpp>
#include "src/game.cpp"
using namespace sf;

int main()
{
  sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Application");

  Game game = Game(window);
  game.run();

  return 0;
}
