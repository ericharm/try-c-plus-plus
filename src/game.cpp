#include "game.h"
#include "hero.h"

#include "textures.cpp"
#include "resource_holder.cpp"

Game::Game() : window(sf::VideoMode(800, 600), "SFML Application") {
  typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;
  TextureHolder textures;
  textures.load(Textures::Hero, "assets/images/hero.png");

  Hero* hero = new Hero(textures);
  this->entities.push_back(hero);

  this->movingUp = false;
  this->movingDown = false;
  this->movingLeft = false;
  this->movingRight = false;
}

void Game::run() {
  sf::Clock clock;
  sf::Time timePerFrame = sf::seconds(1.0f / 30.0f);
  sf::Time timeSinceLastUpdate = sf::Time::Zero;
  while (this->window.isOpen()) {
    this->handleInput();
    timeSinceLastUpdate += clock.restart();
    while (timeSinceLastUpdate > timePerFrame) {
      timeSinceLastUpdate -= timePerFrame;
      this->handleInput();
      this->update(timePerFrame);
    }
    this->render();
  }
}

void Game::handleInput() {
  sf::Event event;
  while (this->window.pollEvent(event))
  {
    switch (event.type) {
      case sf::Event::KeyPressed:
        this->handleKeyPress(event.key.code, true);
        break;
      case sf::Event::KeyReleased:
        this->handleKeyPress(event.key.code, false);
        break;
      case sf::Event::Closed:
        this->window.close();
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
  float speed = 100.0f;
  sf::Vector2f movement(0.f, 0.f);
  if (this->movingUp) movement.y -= speed;
  if (this->movingDown) movement.y += speed;
  if (this->movingLeft) movement.x -= speed;
  if (this->movingRight) movement.x += speed;

  if (!this->entities.empty()) {
    Entity* hero = entities.front();
    hero->update(movement * deltaTime.asSeconds());
  }
}

void Game::render() {
    this->window.clear();
    if (!this->entities.empty()) {
      Entity* hero = entities.front();
      hero->render(this->window);
    }
    this->window.display();
}
