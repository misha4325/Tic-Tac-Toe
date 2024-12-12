#pragma once

#include <iostream>

/**
 * @brief Enum representing the state of a cell.
 */
enum class CellState {
    Empty, ///< The cell is empty.
    Cross, ///< The cell contains a cross.
    Circle ///< The cell contains a circle.
};

/**
 * @brief Input stream operator for CellState.
 * @param in Input stream.
 * @param cell CellState variable.
 * @return Modified input stream.
 */
std::istream& operator>>(std::istream& in, CellState& cell);

/**
 * @brief Output stream operator for CellState.
 * @param out Output stream.
 * @param cell CellState variable.
 * @return Modified output stream.
 */
std::ostream& operator<<(std::ostream& out, const CellState& cell);
