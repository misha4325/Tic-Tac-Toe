#include "board.hpp"



    void Reset(){}  // Очистка игрового поля
    bool SetMove(const Point& position, CellState state){return false;}  // Установка крестика или нолика в клетку
    CellState GetCellState(const Point& position) {CellState temp; return temp;}  // Получение состояния клетки (пустая/крестик/нолик)
    bool IsFull() {return false;}  // Проверка, заполнено ли всё поле
    bool CheckWin(CellState state) {return false;}  // Проверка, победил ли игрок
