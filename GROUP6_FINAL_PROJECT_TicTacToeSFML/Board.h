#pragma once

#include <SFML/Graphics.hpp>
#include "Cell.h"


class Board
{

private:

    Cell cells[3][3];


public:

    bool placeMark(int row, int col, char mark);

    char getCellValue(int row, int col) const;
    
    char checkWinner() const;
    
    bool isFull() const;

    void drawMarks(sf::RenderWindow& window, const sf::Font& font);

    Board();

    ~Board();


    void draw(sf::RenderWindow& window, const sf::Font& font);

    void reset();

};
