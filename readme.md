# Tic-Tac-Toe Classic

## Описание проекта:

Проект `Tic-Tac-Toe Classic` представляет собой цифровую версию классической настольной игры "Крестики-Нолики". Игра реализована с использованием объектно-ориентированного программирования и предназначена для двух игроков. Проект включает в себя базовую логику игры, проверку победы и ничьи, а также простой графический интерфейс для взаимодействия с пользователем. Это удобная платформа для игры на одном устройстве.

5-я лабораторная работа
В рамках данной работы были внесены следующие изменения:

Подключена библиотека SFML (Simple and Fast Multimedia Library), которая используется для графического отображения игрового поля и взаимодействия с пользователем.
Использована SFML в файле game_engine.cpp для создания окна игры и отрисовки игрового поля, а также для обработки ввода от пользователей.
Создана папка libs, в которой находятся статические библиотеки проекта. Это позволяет организовать код и использовать различные части программы как отдельные библиотеки.

## Новые типы данных:

### Point

Структура для работы с координатами на поле.

- `x` — координата по горизонтали.
- `y` — координата по вертикали.

__Описание:__ Представляет положение на игровом поле, используется для указания мест, где игроки могут ставить свои крестики или нолики.

### CellState

Перечисление, описывающее возможные состояния клеток на игровом поле.

- `Empty` — пустая клетка.
- `Cross` — клетка с крестиком.
- `Circle` — клетка с ноликом.

__Описание:__ Используется для хранения текущего состояния каждой клетки на поле и определения, какой символ был помещён.

### Board

Класс, представляющий игровое поле.

- `_grid` — двумерный массив 3x3, представляющий клетки игрового поля.

Методы:

- `Reset()` — очистка поля.
- `SetMove()` — установка символа (крестик или нолик) в указанную клетку.
- `GetCellState()` — возвращает состояние клетки по заданной позиции.
- `IsFull()` — проверяет, заполнено ли поле.
- `CheckWin()` — проверяет, есть ли победитель.

__Описание:__ Управляет состоянием игрового поля и реализует логику игры, включая проверку победы или ничьи.

### Player

Класс игрока.

- `_symbol` — символ игрока (крестик или нолик).

Методы:

- `GetSymbol()` — возвращает символ игрока (крестик или нолик).

__Описание:__ Представляет каждого игрока в игре и управляет его символом.

### GameEngine

Класс, управляющий логикой игры.

- `_board `— объект игрового поля.

- `_player1`, - `_player2` — объекты игроков.

- `_currentPlayer` — текущий игрок, совершающий ход.

Методы:

- `Init()` — инициализирует игру.

- `MakeMove()` — делает ход на поле.

- `SwitchPlayer()` — переключает активного игрока.

- `IsGameOver()` — проверяет, закончилась ли игра.

- `GetWinner()` — возвращает победителя (если есть).

__Описание:__ Этот класс управляет всей игровой логикой, определяет ход игры и взаимодействие между игроками и игровым полем.

### Painter

Класс, отвечающий за визуализацию игры.

Методы:

- `DrawBoard()` — отрисовывает игровое поле.

- `DrawText()` — отображает текстовые сообщения на экране (например, победа или ничья).

__Описание:__ Отвечает за графическое отображение игрового процесса, включая отрисовку поля и вывод информации.

## Зависимости

Для сборки проекта необходимо иметь установленные:

* `g++` - компилятор С++,  рекомендуемая версия 10 или выше
* `make` - система автоматизации сборки, рекомендуемая версия 4 или выше

## Сборка

1. Откройте консоль;
2. Склонируйте проект;
3. Перейдите в папку проекта;
4. Выполните сборку.

```shell
git clone https://github.com/misha4325/Tic-Tac-Toe/tree/lab-02
cd TIC-TAC-TOE
make
```
