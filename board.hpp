#pragma once
#include "point.hpp"
#include "cell.hpp"

class Board {
    CellState _grid[3][3];  // Игровое поле 3x3
public:
    Board()=default;
    void Reset();  // Очистка игрового поля
    bool SetMove(const Point& position, CellState state);  // Установка крестика или нолика в клетку
    CellState GetCellState(const Point& position);  // Получение состояния клетки (пустая/крестик/нолик)
    bool IsFull();  // Проверка, заполнено ли всё поле
    bool CheckWin(CellState state);  // Проверка, победил ли игрок
};