#pragma once

#include "point.hpp"
#include "cell.hpp"
#include <iostream>

class Board {
private:
    CellState _grid[3][3];  // Игровое поле 3x3
    int _width;
    int _height;

public:
    // Конструкторы
    Board();  // Конструктор по умолчанию
    Board(const Board& other);  // Конструктор копирования
    Board(int width, int height);

    // Методы
    int GetWidth() const;
    int GetHeight() const;
    void Reset();  // Очистка игрового поля
    bool SetMove(const Point& position, CellState state);  // Установка крестика или нолика в клетку
    CellState GetCellState(const Point& position) const;  // Получение состояния клетки
    bool IsFull() const;  // Проверка, заполнено ли всё поле
    bool CheckWin(CellState state) const;  // Проверка, победил ли игрок

    // Операторы
    Board& operator=(const Board& other);  // Оператор присваивания
    bool operator==(const Board& other) const;  // Оператор сравнения на равенство
};

// Операторы ввода/вывода
std::istream& operator>>(std::istream& in, Board& board);
std::ostream& operator<<(std::ostream& out, const Board& board);
