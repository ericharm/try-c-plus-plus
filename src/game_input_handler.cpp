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
      hero.setVelocity(0.f, speed * -1.0);
    };
    moveUp.category = Category::Hero;
    commands.push(moveUp);
  }
    // movement.y -= speed;
}
