#include "Game.h"
#include <stdexcept>
#include <iostream>
#include <filesystem>



Game::Game()
    : window(sf::VideoMode({ 800, 600 }), "Tic Tac Toe")
{
    std::cout << "Current working directory:\n"
        << std::filesystem::current_path() << std::endl;

    if (!font.openFromFile("Assets/Roboto-Regular.ttf"))
    {
        std::cerr << "Failed to load font!" << std::endl;
    }

    turnText.emplace(font, "Player X's Turn", 30);
    turnText->setFillColor(sf::Color::Black);
    turnText->setPosition({ 20.f, 20.f });
}


Game::~Game()
{
}


void Game::run()
{
    while (window.isOpen())
    {
        processEvents();

        update();

        render();
    }
}


void Game::processEvents()
{
    while (auto event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            window.close();
        }

        if (auto mouseEvent = event->getIf<sf::Event::MouseButtonPressed>())
        {
            if (mouseEvent->button == sf::Mouse::Button::Left)
            {
                handleMouseClick(
                    mouseEvent->position.x,
                    mouseEvent->position.y);
            }
        }

        if (auto keyEvent = event->getIf<sf::Event::KeyPressed>())
        {
            if (keyEvent->code == sf::Keyboard::Key::R)
            {
                restartGame();
            }
        }
    }
}

void Game::handleMouseClick(int mouseX, int mouseY)
{
    if (gameOver)
    {
        return;
    }

    // Ignore clicks outside the board.
    if (mouseX < 100 || mouseX > 700 ||
        mouseY < 100 || mouseY > 550)
    {
        return;
    }

    // Convert mouse position to board position.
    int col = (mouseX - 100) / 200;
    int row = (mouseY - 100) / 150;

    // Determine whose turn it is.
    char mark = playerXTurn ? 'X' : 'O';

    // Try to place the mark.
    if (board.placeMark(row, col, mark))
    {
        char winner = board.checkWinner();

        if (winner != ' ')
        {
            gameOver = true;

            turnText->setString(
                std::string("Player ") +
                winner +
                " Wins!  Press R to Restart"
            );
        }
        else if (board.isFull())
        {
            gameOver = true;

            turnText->setString("It's a Draw!  Press R to Restart");
        }
        else
        {
            playerXTurn = !playerXTurn;

            turnText->setString(
                playerXTurn ? "Player X's Turn"
                : "Player O's Turn"
            );
        }
    }
}

void Game::restartGame()
{
    board.reset();

    playerXTurn = true;

    gameOver = false;

    turnText->setString("Player X's Turn");
}


void Game::update()
{

}


void Game::render()
{
    window.clear(sf::Color::White);

    board.draw(window, font);

    if (turnText)
    {
        window.draw(*turnText);
    }

    window.display();
}