#include <cassert>
#include <iostream>
#include "point.hpp"
#include "board.hpp"
#include "player.hpp"
#include "game_engine.hpp"

// Тесты для Point
void TestPoint() {
    // Тест конструктора по умолчанию
    Point p1;
    assert(p1.x == 0 && p1.y == 0);

    // Тест параметризованного конструктора
    Point p2(5, 10);
    assert(p2.x == 5 && p2.y == 10);

    // Тест оператора присваивания
    Point p3;
    p3 = p2;
    assert(p3.x == 5 && p3.y == 10);

    // Тест оператора сравнения
    assert(p2 == p3);
    assert(!(p1 == p3));

    std::cout << "TestPoint passed!" << std::endl;
}

// Тесты для Board
void TestBoard() {
    // Тест конструктора по умолчанию
    Board board;
    assert(board.GetWidth() == 3);
    assert(board.GetHeight() == 3);

    // Тест сброса игрового поля
    board.Reset();
    assert(board.GetCellState(Point(0, 0)) == CellState::Empty);

    // Тест установки крестика и проверки состояния клетки
    assert(board.SetMove(Point(0, 0), CellState::Cross));
    assert(board.GetCellState(Point(0, 0)) == CellState::Cross);

    // Тест переполнения клетки
    assert(!board.SetMove(Point(0, 0), CellState::Circle));

    // Тест проверки на заполненность поля
    board.Reset();
    assert(!board.IsFull());

    std::cout << "TestBoard passed!" << std::endl;
}

// Тесты для Player
void TestPlayer() {
    // Тест конструктора по умолчанию
    Player player1(CellState::Cross);
    assert(player1.GetSymbol() == CellState::Cross);

    // Тест оператора сравнения
    Player player2(CellState::Circle);
    assert(!(player1 == player2));

    // Тест оператора присваивания
    player2 = player1;
    assert(player2.GetSymbol() == CellState::Cross);
    assert(player1 == player2);

    std::cout << "TestPlayer passed!" << std::endl;
}

// Тесты для GameEngine
void TestGameEngine() {
    GameEngine engine;
    engine.Init();

    // Тест перехода хода
    assert(engine.MakeMove(Point(0, 0)));
    engine.SwitchPlayer();
    assert(engine.MakeMove(Point(1, 1)));

    // Тест завершения игры
    assert(!engine.IsGameOver());

    std::cout << "TestGameEngine passed!" << std::endl;
}

// Основной тестовый метод
int main() {
    TestPoint();
    TestBoard();
    TestPlayer();
    TestGameEngine();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
