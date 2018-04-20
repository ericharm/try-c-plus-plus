#ifndef COMMAND_CPP
#define COMMAND_CPP
#include <functional>
#include <SFML/System/Time.hpp>

class SceneNode;

struct Command {
  std::function<void(SceneNode&, sf::Time)> action;
  unsigned int category;
};
#endif
