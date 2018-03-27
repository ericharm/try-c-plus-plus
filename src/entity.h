#ifndef ENTITY_H
#define ENTITY_H
#include "resource_holder.cpp"
#include "textures.cpp"
#include <SFML/Graphics.hpp>

class Entity {

  public:
    Entity();
    typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;
    void setVelocity(sf::Vector2f velocity);
    void setVelocity(float x, float y);
    sf::Vector2f getVelocity() const;

    // will be moved to scene node
    virtual void update(sf::Vector2f direction);
    virtual void render(sf::RenderWindow& window);
  private:
    sf::Vector2f velocity;
};
#endif
