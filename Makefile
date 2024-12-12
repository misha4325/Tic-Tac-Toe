# Директории
SRC_DIR = src
LIB_DIR = libs
INCLUDE_DIR = include
SFML_INCLUDE = src/include
SFML_LIB = src/lib

# Компилятор и флаги
CC = g++
CFLAGS = -I$(INCLUDE_DIR) -I$(SFML_INCLUDE) -c
AR = ar
ARFLAGS = rcs

# Библиотеки
LIB_FIELD = $(LIB_DIR)/libBoard.a
LIB_FIGURE = $(LIB_DIR)/libCell.a
LIB_CLEANER = $(LIB_DIR)/libPainter.a
LIB_GAME = $(LIB_DIR)/libPlayer.a
LIB_POINT = $(LIB_DIR)/libPoint.a
LIB_GAME_ENGINE = $(LIB_DIR)/libGameEngine.a

# Все библиотеки
LIBRARIES = $(LIB_FIELD) $(LIB_FIGURE) $(LIB_CLEANER) $(LIB_GAME) $(LIB_POINT) $(LIB_GAME_ENGINE)

# Исходные файлы
MAIN = $(SRC_DIR)/main.cpp
TEST_MAIN = $(SRC_DIR)/test_main.cpp

# Объектные файлы
OBJ_FIELD = $(SRC_DIR)/board.o
OBJ_FIGURE = $(SRC_DIR)/cell.o
OBJ_CLEANER = $(SRC_DIR)/painter.o
OBJ_GAME = $(SRC_DIR)/player.o
OBJ_POINT = $(SRC_DIR)/point.o
OBJ_GAME_ENGINE = $(SRC_DIR)/game_engine.o
OBJ_MAIN = $(SRC_DIR)/main.o
OBJ_TEST_MAIN = $(SRC_DIR)/test_main.o

# Цель по умолчанию
all: Tic-Tac-Toe

# Основное приложение
Tic-Tac-Toe: $(OBJ_MAIN) $(LIBRARIES)
	$(CC) -o Tic-Tac-Toe $(OBJ_MAIN) -L$(LIB_DIR) -L$(SFML_LIB) -lBoard -lCell -lPainter -lPlayer -lPoint -lGameEngine -lsfml-graphics -lsfml-window -lsfml-system

# Компиляция main.cpp
$(OBJ_MAIN): $(MAIN)
	$(CC) $(CFLAGS) $(MAIN) -o $(OBJ_MAIN)

# Тесты
tests: $(OBJ_TEST_MAIN) $(LIBRARIES)
	$(CC) -o tests $(OBJ_TEST_MAIN) -L$(LIB_DIR) -L$(SFML_LIB) -lBoard -lCell -lPainter -lPlayer -lPoint -lGameEngine
	@echo "Тесты собраны: выполните ./tests для запуска"

$(OBJ_TEST_MAIN): $(TEST_MAIN)
	$(CC) $(CFLAGS) $(TEST_MAIN) -o $(OBJ_TEST_MAIN)

# Библиотека Board
$(LIB_FIELD): $(OBJ_FIELD)
	$(AR) $(ARFLAGS) $(LIB_FIELD) $(OBJ_FIELD)

$(OBJ_FIELD): $(SRC_DIR)/board.cpp $(INCLUDE_DIR)/board.hpp
	$(CC) $(CFLAGS) $(SRC_DIR)/board.cpp -o $(OBJ_FIELD)

# Библиотека Cell
$(LIB_FIGURE): $(OBJ_FIGURE)
	$(AR) $(ARFLAGS) $(LIB_FIGURE) $(OBJ_FIGURE)

$(OBJ_FIGURE): $(SRC_DIR)/cell.cpp $(INCLUDE_DIR)/cell.hpp
	$(CC) $(CFLAGS) $(SRC_DIR)/cell.cpp -o $(OBJ_FIGURE)

# Библиотека Painter
$(LIB_CLEANER): $(OBJ_CLEANER)
	$(AR) $(ARFLAGS) $(LIB_CLEANER) $(OBJ_CLEANER)

$(OBJ_CLEANER): $(SRC_DIR)/painter.cpp $(INCLUDE_DIR)/painter.hpp
	$(CC) $(CFLAGS) $(SRC_DIR)/painter.cpp -o $(OBJ_CLEANER)

# Библиотека Player
$(LIB_GAME): $(OBJ_GAME)
	$(AR) $(ARFLAGS) $(LIB_GAME) $(OBJ_GAME)

$(OBJ_GAME): $(SRC_DIR)/player.cpp $(INCLUDE_DIR)/player.hpp
	$(CC) $(CFLAGS) $(SRC_DIR)/player.cpp -o $(OBJ_GAME)

# Библиотека Point
$(LIB_POINT): $(OBJ_POINT)
	$(AR) $(ARFLAGS) $(LIB_POINT) $(OBJ_POINT)

$(OBJ_POINT): $(SRC_DIR)/point.cpp $(INCLUDE_DIR)/point.hpp
	$(CC) $(CFLAGS) $(SRC_DIR)/point.cpp -o $(OBJ_POINT)

# Библиотека GameEngine
$(LIB_GAME_ENGINE): $(OBJ_GAME_ENGINE)
	$(AR) $(ARFLAGS) $(LIB_GAME_ENGINE) $(OBJ_GAME_ENGINE)

$(OBJ_GAME_ENGINE): $(SRC_DIR)/game_engine.cpp $(INCLUDE_DIR)/game_engine.hpp
	$(CC) $(CFLAGS) $(SRC_DIR)/game_engine.cpp -o $(OBJ_GAME_ENGINE)

# Удаление временных файлов
clean:
	rm -f $(SRC_DIR)/*.o Tic-Tac-Toe tests $(LIBRARIES)
