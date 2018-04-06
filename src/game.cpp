#include "game.h"

Game::Game() : window(sf::VideoMode(800, 600), "SFML Application"), world(window) {
}

void Game::run() {
  sf::Clock clock;
  sf::Time timePerFrame = sf::seconds(1.0f / 30.0f);
  sf::Time timeSinceLastUpdate = sf::Time::Zero;
  while (window.isOpen()) {
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
  world.handleInput();
}

void Game::update(sf::Time deltaTime) {
  world.update(deltaTime);
}

void Game::draw() {
    window.clear();
    world.draw();
    window.display();
}
