#pragma once

#include "cell.hpp"  // Убедитесь, что CellState доступен в этом файле

class Player {
    CellState _symbol;  // Используем CellState для обозначения крестика или нолика
public:
    Player() = default;
    explicit Player(CellState symbol);

    CellState GetSymbol() const;

    Player& operator=(const Player& other);
    bool operator==(const Player& other) const;
};
