#include "game.h"
#include "hero.h"

#include "textures.cpp"
#include "resource_holder.cpp"

Game::Game() : window(sf::VideoMode(800, 600), "SFML Application"), world(window) {
  TextureHolder textures;
  textures.load(Textures::Hero, "assets/images/hero.png");

  Hero* hero = new Hero(textures);
  entities.push_back(hero);

  movingUp = false;
  movingDown = false;
  movingLeft = false;
  movingRight = false;
}

void Game::run() {
  sf::Clock clock;
  sf::Time timePerFrame = sf::seconds(1.0f / 30.0f);
  sf::Time timeSinceLastUpdate = sf::Time::Zero;
  while (window.isOpen()) {
    handleInput();
    timeSinceLastUpdate += clock.restart();
    while (timeSinceLastUpdate > timePerFrame) {
      timeSinceLastUpdate -= timePerFrame;
      handleInput();
      update(timePerFrame);
    }
    draw();
  }
}

void Game::handleInput() {
  // world.handleInput();
  sf::Event event;
  while (window.pollEvent(event))
  {
    switch (event.type) {
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

void Game::handleKeyPress(sf::Keyboard::Key key, bool pressed) {
  if (key == sf::Keyboard::Up) {
    this->movingUp = pressed;
  } else if (key == sf::Keyboard::Left) {
    this->movingLeft = pressed;
  } else if (key == sf::Keyboard::Down) {
    this->movingDown = pressed;
  } else if (key == sf::Keyboard::Right) {
    this->movingRight = pressed;
  }
}

void Game::update(sf::Time deltaTime) {
  // float speed = 100.0f;
  // sf::Vector2f movement(0.f, 0.f);
  // if (movingUp) movement.y -= speed;
  // if (movingDown) movement.y += speed;
  // if (movingLeft) movement.x -= speed;
  // if (movingRight) movement.x += speed;

  // for (Entity* entity :entities) {
    // once we add another entity
    // this will have to move into an input controller
    // that uses the command/action system
    // entity->setVelocity(movement);
    // entity->update(deltaTime);
  // }
  world.update(deltaTime);
}

void Game::draw() {
    window.clear();
    world.draw();
    // for (Entity* entity : entities) {
      // window.draw(*entity);
    // }
    window.display();
}
