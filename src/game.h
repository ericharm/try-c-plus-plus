#include <SFML/Graphics.hpp>

using namespace std;

class Game {

  public:
    Game();
    void run();

  private:
    void handleInput();
    void update();
    void render();

  private:
    sf::RenderWindow window;
    sf::CircleShape hero;

};
