#include <iostream>
#include <SFML/Graphics.hpp>
#include "src/game.h"

using namespace sf;

namespace Textures
{
  enum ID
  {
    Hero,
  };
}

class TextureHolder {

  public:
    void load(Textures::ID, const std::string& filename) {

    }

    sf::Sprite get(Textures::ID) {
      sf::Texture texture = sf::Texture();
      if (!texture.loadFromFile("assets/images/hero.png")) {
        throw "FileNotFound";
      }
      sf::Sprite sprite = sf::Sprite(texture);
      return sprite;
    }

  // private:
    // std::string& filename;
};


int main()
{

  TextureHolder textures;
  try {
    textures.load(Textures::Hero, "assets/images/hero.png");
  }
  catch (std::runtime_error& e) {
    std::cout << "Exception: " << e.what() << std::endl;
    return 1;
  }

  sf::Sprite hero(textures.get(Textures::Hero));


  Game game;
  game.run();
  return 0;
}
