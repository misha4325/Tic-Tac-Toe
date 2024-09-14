#pragma once
#include "point.hpp"
#include "board.hpp"

class Painter {
public:
    void DrawBoard(const Board& board);  // Рисует игровое поле
    void DrawText(Point position, const char* text);  // Рисует текст в указанной позиции
};