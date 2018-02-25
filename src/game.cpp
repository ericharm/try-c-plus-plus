#include <SFML/Graphics.hpp>
#include "game.h"
#include "hero.cpp"

using namespace std;

Game::Game() : window(sf::VideoMode(640, 480), "SFML Application") {
  this->hero = Hero();

  this->movingUp = false;
  this->movingDown = false;
  this->movingLeft = false;
  this->movingRight = false;
}

void Game::run() {
  while (this->window.isOpen()) {
    this->handleInput();
    this->update();
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
  if (key == sf::Keyboard::W) {
    this->movingUp = pressed;
  } else if (key == sf::Keyboard::A) {
    this->movingLeft = pressed;
  } else if (key == sf::Keyboard::S) {
    this->movingDown = pressed;
  } else if (key == sf::Keyboard::D) {
    this->movingRight = pressed;
  }
}

void Game::update() {
  float speed = 1;
  sf::Vector2f movement(0.f, 0.f);
  if (this->movingUp)
    movement.y -= speed;
  if (this->movingDown)
    movement.y += speed;
  if (this->movingLeft)
    movement.x -= speed;
  if (this->movingRight)
    movement.x += speed;
  this->hero.update(movement);
}

void Game::render() {
    this->window.clear();
    this->hero.render(this->window);
    this->window.display();
}

