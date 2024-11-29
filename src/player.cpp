#include "player.hpp"

Player::Player(CellState symbol) : _symbol(symbol) {}

CellState Player::GetSymbol() const {
    return _symbol;
}

Player& Player::operator=(const Player& other) {
    if (this != &other) {
        _symbol = other._symbol;
    }
    return *this;
}

bool Player::operator==(const Player& other) const {
    return _symbol == other._symbol;
}

// Здесь можно реализовать операторы ввода/вывода для CellState, если это требуется
