#pragma once

#include "point.hpp"
#include "cell.hpp"
#include <iostream>

/**
 * @brief Class representing the game board.
 */
class Board {
private:
    CellState _grid[3][3]; ///< 3x3 grid representing the game board.
    int _width;           ///< Width of the board.
    int _height;          ///< Height of the board.

public:
    /**
     * @brief Default constructor.
     */
    Board();

    /**
     * @brief Copy constructor.
     * @param other Another Board instance to copy.
     */
    Board(const Board& other);

    /**
     * @brief Constructs a board with specified dimensions.
     * @param width Width of the board.
     * @param height Height of the board.
     */
    Board(int width, int height);

    /**
     * @brief Gets the board's width.
     * @return Width of the board.
     */
    int GetWidth() const;

    /**
     * @brief Gets the board's height.
     * @return Height of the board.
     */
    int GetHeight() const;

    /**
     * @brief Resets the board, clearing all cells.
     */
    void Reset();

    /**
     * @brief Sets a move on the board.
     * @param position Coordinates where the move is made.
     * @param state The cell state (Cross or Circle).
     * @return True if the move is valid and applied, false otherwise.
     */
    bool SetMove(const Point& position, CellState state);

    /**
     * @brief Gets the state of a specific cell.
     * @param position Coordinates of the cell.
     * @return State of the cell.
     */
    CellState GetCellState(const Point& position) const;

    /**
     * @brief Checks if the board is completely filled.
     * @return True if the board is full, false otherwise.
     */
    bool IsFull() const;

    /**
     * @brief Checks if the given player has won.
     * @param state Cell state to check for a win.
     * @return True if the player has won, false otherwise.
     */
    bool CheckWin(CellState state) const;

    /**
     * @brief Assignment operator.
     * @param other Another Board instance to assign.
     * @return Reference to the current Board instance.
     */
    Board& operator=(const Board& other);

    /**
     * @brief Equality operator.
     * @param other Another Board instance to compare.
     * @return True if both boards are equal, false otherwise.
     */
    bool operator==(const Board& other) const;
};

/**
 * @brief Input stream operator for Board.
 * @param in Input stream.
 * @param board Board instance.
 * @return Modified input stream.
 */
std::istream& operator>>(std::istream& in, Board& board);

/**
 * @brief Output stream operator for Board.
 * @param out Output stream.
 * @param board Board instance.
 * @return Modified output stream.
 */
std::ostream& operator<<(std::ostream& out, const Board& board);
