#include "player.hpp"

    Player::Player(CellState symbol){}
    CellState Player::GetSymbol() {CellState test;return test;}

    // Оператор присваивания
    Player& Player::operator=(const Player &other) {
    if (this != &other) {
        _symbol = other._symbol;
    }
    return *this;
}

    // Оператор сравнения
    bool Player::operator==(const Player &other) const {
    return _symbol==other._symbol;
}