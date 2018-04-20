#include "world.h"

World::World(sf::RenderWindow& w) : window(w), spawnPoint(100.0f, 100.0f) {
  loadTextures();
  buildScene();
}

void World::update(sf::Time deltaTime) {
  // should be able to called inputController->handleInput();
  // float speed = 100.0f;
  // sf::Vector2f movement(0.f, 0.f);
  // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    // movement.y -= speed;
  // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    // movement.y += speed;
  // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    // movement.x -= speed;
  // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    // movement.x += speed;
  // hero->setVelocity(movement);

  while (!commandQueue.isEmpty())
    sceneGraph.onCommand(commandQueue.pop(), deltaTime);

  hero->update(deltaTime);
}

void World::draw() {
  window.draw(sceneGraph);
}

void World::loadTextures() {
  textures.load(Textures::Hero, "assets/images/hero.png");
}

void World::buildScene() {
  for (std::size_t i = 0; i < LayerCount; i++) {
    SceneNode::NodePtr layer(new SceneNode());
    layers[i] = layer.get();
    sceneGraph.attachChild(std::move(layer));
  }

  std::unique_ptr<Hero> h(new Hero(textures));
  hero = h.get();
  hero->setPosition(spawnPoint);
  layers[Foreground]->attachChild(std::move(h));
}

CommandQueue& World::getCommandQueue() {
  return commandQueue;
}
