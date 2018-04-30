#include <iostream>
#include "game_input_handler.h"
#include "hero.h"
#include "command.cpp"
#include "category.cpp"
#include "direction.cpp"

void GameInputHandler::handleEvent(const sf::Event& event, CommandQueue& commands) {

}

void GameInputHandler::handleRealtimeInput(CommandQueue& commands) {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    Command move; 
    move.action = [] (SceneNode& node, sf::Time dt) {
      Hero& hero = static_cast<Hero&>(node);
      hero.setMoving(Up);
    };
    move.category = Category::Hero;
    commands.push(move);
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
    Command move; 
    move.action = [] (SceneNode& node, sf::Time dt) {
      Hero& hero = static_cast<Hero&>(node);
      hero.setMoving(Down);
    };
    move.category = Category::Hero;
    commands.push(move);
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    Command move; 
    move.action = [] (SceneNode& node, sf::Time dt) {
      Hero& hero = static_cast<Hero&>(node);
      hero.setMoving(Left);
    };
    move.category = Category::Hero;
    commands.push(move);
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    Command move; 
    move.action = [] (SceneNode& node, sf::Time dt) {
      Hero& hero = static_cast<Hero&>(node);
      hero.setMoving(Right);
    };
    move.category = Category::Hero;
    commands.push(move);
  }
}

