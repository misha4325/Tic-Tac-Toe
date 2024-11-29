#pragma once
#include "cell.hpp"
#include <string>

class Player {
    CellState _symbol;  // Крестик или нолик
public:
    Player() = default;
    explicit Player(CellState symbol);

    CellState GetSymbol() const;

    // Оператор присваивания
    Player& operator=(const Player& other);

    // Оператор сравнения
    bool operator==(const Player& other) const;
};

// Операторы ввода и вывода
std::istream& operator>>(std::istream& in, CellState& cell);
std::ostream& operator<<(std::ostream& out, const CellState& cell);