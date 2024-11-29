
#include "game_engine.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

// Constructor
GameEngine::GameEngine()
    : _board(3, 3),  // Initialize a 3x3 board
      _player1(CellState::Circle),
      _player2(CellState::Cross),
      _currentPlayer(&_player1) {}

// Initialize game
void GameEngine::Init() {
    _board.Reset();  // Clear the board for a new game
    _currentPlayer = &_player1;
}

// Run the game loop
void GameEngine::Run() {
    sf::RenderWindow window(sf::VideoMode(600, 600), "Tic-Tac-Toe");

    // Drawing helpers
    auto createCellText = [&](CellState state) -> sf::Text {
        sf::Text text;
        text.setCharacterSize(60);
        text.setFillColor(sf::Color::Black);
        text.setString(state == CellState::Cross ? "X" : (state == CellState::Circle ? "O" : ""));
        return text;
    };

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                Point position(mousePos.x / 200, mousePos.y / 200);  // Convert pixel to board grid
                if (MakeMove(position)) {
                    if (IsGameOver()) {
                        Player* winner = GetWinner();
                        std::cout << (winner ? winner->GetSymbol() == CellState::Cross ? "Player 1 wins!" : "Player 2 wins!" : "It's a draw!") << std::endl;
                        window.close();
                    } else {
                        SwitchPlayer();
                    }
                }
            }
        }

        // Clear and render board
        window.clear(sf::Color::White);

        // Draw grid lines
        for (int i = 1; i < 3; ++i) {
            sf::RectangleShape vertical(sf::Vector2f(5, 600));
            vertical.setPosition(i * 200, 0);
            vertical.setFillColor(sf::Color::Black);
            window.draw(vertical);

            sf::RectangleShape horizontal(sf::Vector2f(600, 5));
            horizontal.setPosition(0, i * 200);
            horizontal.setFillColor(sf::Color::Black);
            window.draw(horizontal);
        }

        // Draw symbols
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                sf::Text cellText = createCellText(_board.GetCellState(Point(i, j)));
                cellText.setPosition(i * 200 + 75, j * 200 + 50);
                window.draw(cellText);
            }
        }

        window.display();
    }
}

// Make a move on the board
bool GameEngine::MakeMove(const Point& position) {
    if (_board.SetMove(position, _currentPlayer->GetSymbol())) {
        return true;
    }
    std::cout << "Invalid move! Try again." << std::endl;
    return false;
}

// Switch the current player
void GameEngine::SwitchPlayer() {
    _currentPlayer = (_currentPlayer == &_player1) ? &_player2 : &_player1;
}

// Check if the game is over
bool GameEngine::IsGameOver() const {
    return _board.CheckWin(CellState::Cross) || _board.CheckWin(CellState::Circle) || _board.IsFull();
}

// Get the winner of the game
Player* GameEngine::GetWinner() const {
    if (_board.CheckWin(CellState::Cross)) {
        return const_cast<Player*>(&_player1);  // Convert to non-const pointer
    }
    if (_board.CheckWin(CellState::Circle)) {
        return const_cast<Player*>(&_player2);  // Convert to non-const pointer
    }
    return nullptr;
}
