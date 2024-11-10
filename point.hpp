#pragma once
#include <iostream>
#include <string>

struct Point {
    int x;
    int y;

    Point(int _x = 0, int _y = 0);
    Point(const Point& other);

    Point& operator=(const Point& other);  // Возвращает Point&
    bool operator==(const Point& other) const;
};

// Операторы ввода и вывода
std::istream& operator>>(std::istream& in, Point& point);
std::ostream& operator<<(std::ostream& out, const Point& point);
