#pragma once

#include "cell.hpp" ///< For CellState enum

/**
 * @brief Class representing a player in the game.
 */
class Player {
    CellState _symbol; ///< Symbol of the player (Cross or Circle).

public:
    /**
     * @brief Default constructor.
     */
    Player() = default;

    /**
     * @brief Constructor with symbol initialization.
     * @param symbol Symbol assigned to the player.
     */
    explicit Player(CellState symbol);

    /**
     * @brief Gets the player's symbol.
     * @return The player's symbol.
     */
    CellState GetSymbol() const;

    /**
     * @brief Assignment operator.
     * @param other Another Player instance to assign.
     * @return Reference to the current Player instance.
     */
    Player& operator=(const Player& other);

    /**
     * @brief Equality operator.
     * @param other Another Player instance to compare.
     * @return True if the players are equal, false otherwise.
     */
    bool operator==(const Player& other) const;
};
