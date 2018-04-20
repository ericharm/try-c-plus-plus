#ifndef COMMAND_QUEUE_H
#define COMMAND_QUEUE_H

#include <queue>
#include "command.cpp"

class CommandQueue {

  public:
    void push(const Command& command);
    Command pop();
    bool isEmpty() const;

  private:
    std::queue<Command> queue;
};
#endif
