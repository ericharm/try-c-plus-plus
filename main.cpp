#include <SFML/Graphics.hpp>
#include "game.cpp"
using namespace sf;

int main()
{
  sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

  sf::CircleShape shape = sf::CircleShape(100.f);
  shape.setFillColor(sf::Color::Red);

  Game game = Game(window, shape);
  game.run();

  return 0;
}
