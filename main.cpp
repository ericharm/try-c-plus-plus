#include <iostream>
#include <SFML/Graphics.hpp>
#include "src/textures.cpp"
#include "src/resource_holder.cpp"
#include "src/game.h"

using namespace sf;

int main() {
  typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;
  TextureHolder textures;
  textures.load(Textures::Hero, "assets/images/hero.png");

  Game game(&textures);
  game.run();
  return 0;
}
