#include <SFML/Graphics.hpp>
#include "game.h"

using namespace std;

Game::Game(sf::RenderWindow& window) : window(window) {
  this->hero = sf::CircleShape(100.f);
  this->hero.setFillColor(sf::Color::Red);
}

void Game::run() {
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    window.clear();
    window.draw(this->hero);
    window.display();
  }
}

void Game::handleInput() {
}

void Game::update() {
}

void Game::render() {
}

