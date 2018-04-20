#include <iostream>
#include "game_input_handler.h"
#include "hero.h"
#include "command.cpp"
#include "category.cpp"

void GameInputHandler::handleEvent(const sf::Event& event, CommandQueue& commands) {

}

void GameInputHandler::handleRealtimeInput(CommandQueue& commands) {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    Command moveUp; 
    moveUp.action = [] (SceneNode& node, sf::Time dt) {
      float speed = 100.0;
      Hero& hero = static_cast<Hero&>(node);
      sf::Vector2f velocity(0.f, speed * -1.0);
      hero.accelerate(velocity);
    };
    moveUp.category = Category::Hero;
    commands.push(moveUp);
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
    Command moveUp; 
    moveUp.action = [] (SceneNode& node, sf::Time dt) {
      float speed = 100.0;
      Hero& hero = static_cast<Hero&>(node);
      sf::Vector2f velocity(0.f, speed);
      hero.accelerate(velocity);
    };
    moveUp.category = Category::Hero;
    commands.push(moveUp);
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    Command moveUp; 
    moveUp.action = [] (SceneNode& node, sf::Time dt) {
      float speed = 100.0;
      Hero& hero = static_cast<Hero&>(node);
      sf::Vector2f velocity(speed * -1.f, 0.f);
      hero.accelerate(velocity);
    };
    moveUp.category = Category::Hero;
    commands.push(moveUp);
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    Command moveUp; 
    moveUp.action = [] (SceneNode& node, sf::Time dt) {
      float speed = 100.0;
      Hero& hero = static_cast<Hero&>(node);
      sf::Vector2f velocity(speed, 0.f);
      hero.accelerate(velocity);
    };
    moveUp.category = Category::Hero;
    commands.push(moveUp);
  }
}

