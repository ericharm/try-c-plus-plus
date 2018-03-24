#include <iostream>
#include <SFML/Graphics.hpp>
#include "src/textures.cpp"
#include "src/resource_holder.h"
#include "src/game.h"

using namespace sf;

int main() {
  ResourceHolder<sf::Texture, Textures::ID> textures;
  textures.load(Textures::Hero, "assets/images/hero.png");

  Game game(&textures);
  game.run();
  return 0;
}
