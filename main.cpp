#include <SFML/Graphics.hpp>
#include "src/game.cpp"
using namespace sf;

int main()
{
  sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

  Game game = Game(window);
  game.run();

  return 0;
}
