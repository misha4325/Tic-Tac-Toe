#pragma once

#include <iostream>

enum class CellState {
    Empty, Cross, Circle
};

// Операторы ввода/вывода
std::istream& operator>>(std::istream& in, CellState& cell);
std::ostream& operator<<(std::ostream& out, const CellState& cell);
