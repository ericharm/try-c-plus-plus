#ifndef WORLD_H
#define WORLD_H
#include <array>
#include "scene_node.h"
#include "hero.h"
#include "textures.cpp"

class World : private sf::NonCopyable {

  public:
    explicit World(sf::RenderWindow& w);
    void update(sf::Time deltaTime);
    void draw();
    void handleInput();

  private:
    void loadTextures();
    void buildScene();

  private:
    enum Layers {
      Foreground,
      LayerCount
    };

  private:
    sf::RenderWindow& window;
    SceneNode sceneGraph;
    sf::FloatRect worldBounds;
    std::array<SceneNode*, LayerCount> layers;
    sf::Vector2f spawnPoint;
    Hero* hero;
    SceneNode::TextureHolder textures;
};
#endif
