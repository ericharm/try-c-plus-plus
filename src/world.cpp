#include "world.h"

World::World(sf::RenderWindow& w) : window(w), spawnPoint(100.0f, 100.0f) {
  loadTextures();
  buildScene();
}

void World::update(sf::Time deltaTime) {
  // should be able to called inputController->handleInput();
  float speed = 100.0f;
  sf::Vector2f movement(0.f, 0.f);
  if (movingUp) movement.y -= speed;
  if (movingDown) movement.y += speed;
  if (movingLeft) movement.x -= speed;
  if (movingRight) movement.x += speed;

  hero->setVelocity(movement);
  hero->update(deltaTime);
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
      // break out into input handler class
      case sf::Event::KeyPressed:
        handleKeyPress(event.key.code, true);
        break;
      case sf::Event::KeyReleased:
        handleKeyPress(event.key.code, false);
        break;

      case sf::Event::Closed:
        window.close();
        break;
      default:
        ;
    }
  }
}

void World::handleKeyPress(sf::Keyboard::Key key, bool pressed) {
  if (key == sf::Keyboard::Up) {
    movingUp = pressed;
  } else if (key == sf::Keyboard::Left) {
    movingLeft = pressed;
  } else if (key == sf::Keyboard::Down) {
    movingDown = pressed;
  } else if (key == sf::Keyboard::Right) {
    movingRight = pressed;
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
