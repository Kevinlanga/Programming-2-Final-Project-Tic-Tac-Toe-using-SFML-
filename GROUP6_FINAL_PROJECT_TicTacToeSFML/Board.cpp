#include "Board.h"


Board::Board()
{

}


Board::~Board()
{

}


void Board::reset()
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            cells[row][col].setValue(' ');
        }
    }
}



void Board::draw(sf::RenderWindow& window, const sf::Font& font)
{
    sf::RectangleShape line;
    line.setFillColor(sf::Color::Black);

    // Horizontal lines
    for (int i = 1; i < 3; i++)
    {
        line.setSize(sf::Vector2f(600.f, 4.f));
        line.setPosition(sf::Vector2f(100.f, 100.f + i * 150.f));
        window.draw(line);
    }

    // Vertical lines
    for (int i = 1; i < 3; i++)
    {
        line.setSize(sf::Vector2f(4.f, 450.f));
        line.setPosition(sf::Vector2f(100.f + i * 200.f, 100.f));
        window.draw(line);
    }

    drawMarks(window, font);
}

bool Board::placeMark(int row, int col, char mark)
{
    if (cells[row][col].isEmpty())
    {
        cells[row][col].setValue(mark);
        return true;
    }

    return false;
}

char Board::getCellValue(int row, int col) const
{
    return cells[row][col].getValue();
}

void Board::drawMarks(sf::RenderWindow& window, const sf::Font& font)
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            char value = cells[row][col].getValue();

            if (value != ' ')
            {
                sf::Text text(font);

                text.setString(std::string(1, value));
                text.setCharacterSize(72);
                text.setFillColor(sf::Color::Red);

                float x = 165.f + col * 200.f;
                float y = 115.f + row * 150.f;

                text.setPosition({ x, y });

                window.draw(text);
            }
        }
    }
}

char Board::checkWinner() const
{
    // Check rows
    for (int row = 0; row < 3; row++)
    {
        char first = cells[row][0].getValue();

        if (first != ' ' &&
            first == cells[row][1].getValue() &&
            first == cells[row][2].getValue())
        {
            return first;
        }
    }

    // Check columns
    for (int col = 0; col < 3; col++)
    {
        char first = cells[0][col].getValue();

        if (first != ' ' &&
            first == cells[1][col].getValue() &&
            first == cells[2][col].getValue())
        {
            return first;
        }
    }

    // Check main diagonal
    char first = cells[0][0].getValue();

    if (first != ' ' &&
        first == cells[1][1].getValue() &&
        first == cells[2][2].getValue())
    {
        return first;
    }

    // Check other diagonal
    first = cells[0][2].getValue();

    if (first != ' ' &&
        first == cells[1][1].getValue() &&
        first == cells[2][0].getValue())
    {
        return first;
    }

    return ' ';
}

bool Board::isFull() const
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (cells[row][col].isEmpty())
            {
                return false;
            }
        }
    }

    return true;
}