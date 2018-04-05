#include "world.h"

World::World(sf::RenderWindow& w) : window(w), spawnPoint(100.0f, 100.0f) {
  // sceneGraph = 
  loadTextures();
  buildScene();
}

void World::update(sf::Time deltaTime) {
  // std::cout << "Updating world" << std::endl;
}

void World::draw() {
  window.draw(sceneGraph);
}

void World::loadTextures() {
  textures.load(Textures::Hero, "assets/images/hero.png");
}

void World::handleInput() {
  sf::Event event;
  while (window.pollEvent(event))
  {
    switch (event.type) {
      // case sf::Event::KeyPressed:
        // handleKeyPress(event.key.code, true);
        // break;
      // case sf::Event::KeyReleased:
        // handleKeyPress(event.key.code, false);
        // break;
      case sf::Event::Closed:
        window.close();
        break;
      default:
        ;
    }
  }
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
