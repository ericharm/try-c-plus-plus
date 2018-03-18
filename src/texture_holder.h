#ifndef TEXTURE_HOLDER_H
#define TEXTURE_HOLDER_H
#include <SFML/Graphics.hpp>
#include "textures.cpp"

class TextureHolder {

  public:
    void load(Textures::ID id, const std::string& filename);
    sf::Texture& get(Textures::ID id);
    const sf::Texture& get(Textures::ID id) const;

  private:
    std::map<Textures::ID, std::unique_ptr<sf::Texture> > textureMap;
};

#endif
