/*#include "board.hpp"



    void Reset(){}  // Очистка игрового поля
    bool SetMove(const Point& position, CellState state){return false;}  // Установка крестика или нолика в клетку
    CellState GetCellState(const Point& position) {CellState temp; return temp;}  // Получение состояния клетки (пустая/крестик/нолик)
    bool IsFull() {return false;}  // Проверка, заполнено ли всё поле
    bool CheckWin(CellState state) {return false;}  // Проверка, победил ли игрок
*/
#include "board.hpp"

// Конструктор по умолчанию
Board::Board() {}

// Конструктор с параметрами
Board::Board(int width, int height) : _width(width), _height(height) {}

// Копирующий конструктор
Board::Board(const Board &other) : _width(other._width), _height(other._height) {}

int Board::GetWidth() const
{
    return _width;
}

int Board::GetHeight() const
{
    return _height;
}

// Метод для очистки игрового поля
void Board::Reset() {
    // Здесь будет логика для очистки игрового поля
}

// Метод для установки крестика или нолика в клетку
bool Board::SetMove(const Point& position, CellState state) {
    // Здесь будет логика для установки крестика или нолика в клетку
    return false;
}

// Метод для получения состояния клетки (пустая/крестик/нолик)
CellState Board::GetCellState(const Point& position) const {
    CellState temp;
    // Здесь будет логика для получения состояния клетки
    return temp;
}

// Метод для проверки, заполнено ли всё поле
bool Board::IsFull() const {
    // Здесь будет логика для проверки, заполнено ли поле
    return false;
}

// Метод для проверки, победил ли игрок
bool Board::CheckWin(CellState state) const {
    // Здесь будет логика для проверки победы игрока
    return false;
}

// Оператор присваивания
Board& Board::operator=(const Board &other) {
    if (this != &other) {
        _width = other._width;
        _height = other._height;
    }
    return *this;
}

// Оператор сравнения
bool Board::operator==(const Board &other) const {
    return _width == other._width && _height == other._height;
}

// Оператор ввода
std::istream& operator>>(std::istream &in, Board &board) {
    int width, height;
    in >> width >> height;
    board = Board(width, height);
    return in;
}

// Оператор вывода
std::ostream& operator<<(std::ostream &out, const Board &board) {
    out << board.GetWidth() << " " << board.GetHeight();
    return out;
}
