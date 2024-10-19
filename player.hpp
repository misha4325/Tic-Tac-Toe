#pragma once
#include "cell.hpp"

class Player {
    CellState _symbol;  // Крестик или нолик
public:
    Player() = default;
    Player(CellState symbol);
    CellState GetSymbol();
};
std::istream& operator>>(std::istream& in, CellState & cell);
std::ostream& operator<<(std::ostream& out, const CellState& cell);
