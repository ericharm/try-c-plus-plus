#ifndef GAME_INPUT_HANDLER_H
#define GAME_INPUT_HANDLER_H
#include <SFML/Graphics.hpp>
#include "command_queue.h"

class GameInputHandler {
  public:
    void handleEvent(const sf::Event& event, CommandQueue& commands);
    void handleRealtimeInput(CommandQueue& commands);

};
#endif
