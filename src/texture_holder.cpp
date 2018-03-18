#include "texture_holder.h"
#include "textures.cpp"
#include <cassert>

void TextureHolder::load(Textures::ID id, const std::string& filename) {
  std::unique_ptr<sf::Texture> texture(new sf::Texture());
  if (!texture->loadFromFile(filename))
    throw std::runtime_error("TextureHolder::load - Failed to load " + filename);
  auto inserted = textureMap.insert(std::make_pair(id, std::move(texture)));
  assert(inserted.second);
}

sf::Texture& TextureHolder::get(Textures::ID id) {
  auto found = textureMap.find(id);
  assert(found != textureMap.end());
  return *found->second;
}

const sf::Texture& TextureHolder::get(Textures::ID id) const {
  auto found = textureMap.find(id);
  return *found->second;
}
