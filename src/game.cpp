#include <SFML/Graphics.hpp>
#include "game.h"

using namespace std;

Game::Game() : window(sf::VideoMode(640, 480), "SFML Application") {
  this->hero = sf::CircleShape(100.f);
  this->hero.setRadius(10.f);
  this->hero.setPosition(10.f, 10.f);
  this->hero.setFillColor(sf::Color::Red);
}

void Game::run() {
  while (this->window.isOpen()) {
    sf::Event event;

    while (this->window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        this->window.close();
    }

    this->render();

  }
}

void Game::handleInput() {
}

void Game::update() {
}

void Game::render() {
    this->window.clear();
    this->window.draw(this->hero);
    this->window.display();
}

