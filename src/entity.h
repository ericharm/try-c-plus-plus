#ifndef ENTITY_H
#define ENTITY_H
#include "resource_holder.cpp"
#include "scene_node.h"
#include "textures.cpp"
#include <SFML/Graphics.hpp>

class Entity : public SceneNode {

  public:
    typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;
    void setVelocity(sf::Vector2f velocity);
    void setVelocity(float x, float y);
    sf::Vector2f getVelocity() const;

    // will be moved to scene node
    virtual void updatex(sf::Vector2f direction);

  private:
    virtual void updateCurrent(sf::Time dt);

  private:
    sf::Vector2f velocity;
};
#endif
