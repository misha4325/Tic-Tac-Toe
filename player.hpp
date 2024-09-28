#pragma once
#include "cell.hpp"

class Player {
    CellState _symbol;  // Крестик или нолик
public:
    Player() = default;
    Player(CellState symbol);
    CellState GetSymbol();
};