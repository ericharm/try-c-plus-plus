#include <SFML/Graphics.hpp>

using namespace std;

class Game {

  public:
    Game(sf::RenderWindow& window);
    void run();

  private:
    void handleInput();
    void update();
    void render();

  private:
    sf::RenderWindow& window;
    sf::CircleShape hero;

};
