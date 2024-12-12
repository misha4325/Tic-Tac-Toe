#pragma once
#include "board.hpp"
#include "player.hpp"
#include "point.hpp"

/**
 * @brief Class for managing the game logic.
 */
class GameEngine {
    Board _board;          ///< Game board.
    Player _player1;       ///< First player.
    Player _player2;       ///< Second player.
    Player* _currentPlayer; ///< Pointer to the current player.

public:
    /**
     * @brief Default constructor.
     */
    GameEngine();

    /**
     * @brief Initializes the game.
     */
    void Init();

    /**
     * @brief Runs the game loop.
     */
    void Run();

    /**
     * @brief Makes a move on the board.
     * @param position Coordinates of the move.
     * @return True if the move was successful, false otherwise.
     */
    bool MakeMove(const Point& position);

    /**
     * @brief Switches to the next player's turn.
     */
    void SwitchPlayer();

    /**
     * @brief Checks if the game is over.
     * @return True if the game is over, false otherwise.
     */
    bool IsGameOver() const;

    /**
     * @brief Gets the winner of the game.
     * @return Pointer to the winning player, or nullptr if no winner.
     */
    Player* GetWinner() const;

    /**
     * @brief Renders the game board and UI.
     */
    void Render();
};
