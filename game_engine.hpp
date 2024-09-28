#pragma once
#include "board.hpp"
#include "player.hpp"
#include "point.hpp"

class GameEngine {
    Board _board;
    Player _player1;
    Player _player2;
    Player* _currentPlayer;  // Указатель на текущего игрока
public:
    GameEngine();
    void Init();  // Инициализация игры
    void Run();
    bool MakeMove(const Point& position);  // Совершить ход на поле
    void SwitchPlayer();  // Переход хода к следующему игроку
    bool IsGameOver() const;  // Проверка завершения игры
    Player* GetWinner() const;  // Возвращает победителя (если есть)
};