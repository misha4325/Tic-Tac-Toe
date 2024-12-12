#pragma once
#include <iostream>
#include <string>

/**
 * @brief Structure representing a 2D point.
 */
struct Point {
    int x; ///< X-coordinate of the point.
    int y; ///< Y-coordinate of the point.

    /**
     * @brief Constructor with default or custom initialization.
     * @param _x X-coordinate (default 0).
     * @param _y Y-coordinate (default 0).
     */
    Point(int _x = 0, int _y = 0);

    /**
     * @brief Copy constructor.
     * @param other Another Point instance to copy.
     */
    Point(const Point& other);

    /**
     * @brief Assignment operator.
     * @param other Another Point instance to assign.
     * @return Reference to the current Point instance.
     */
    Point& operator=(const Point& other);

    /**
     * @brief Equality operator.
     * @param other Another Point instance to compare.
     * @return True if the points are equal, false otherwise.
     */
    bool operator==(const Point& other) const;
};

/**
 * @brief Input stream operator for Point.
 * @param in Input stream.
 * @param point Point instance.
 * @return Modified input stream.
 */
std::istream& operator>>(std::istream& in, Point& point);

/**
 * @brief Output stream operator for Point.
 * @param out Output stream.
 * @param point Point instance.
 * @return Modified output stream.
 */
std::ostream& operator<<(std::ostream& out, const Point& point);
