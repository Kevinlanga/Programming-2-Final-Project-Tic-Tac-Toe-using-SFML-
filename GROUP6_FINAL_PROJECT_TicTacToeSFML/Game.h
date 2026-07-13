#pragma once

#include <SFML/Graphics.hpp>
#include "Board.h"

class Game
{
private:

    sf::RenderWindow window;

    sf::Font font;
    std::optional<sf::Text> turnText;

    Board board;

    bool playerXTurn = true;
    bool gameOver = false;

    void processEvents();
    void update();
    void render();

    void handleMouseClick(int mouseX, int mouseY);
    void restartGame();

public:

    Game();

    ~Game();

    void run();
};
