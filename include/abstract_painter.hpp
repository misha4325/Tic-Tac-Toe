#pragma once

#include "point.hpp"

/**
 * @brief Abstract interface for painting graphics and text.
 */
struct AbstractPainter {
    /**
     * @brief Draws an image within the specified rectangle.
     * @param topLeft Top-left corner of the rectangle.
     * @param bottomRight Bottom-right corner of the rectangle.
     * @param image 2D array representing the image.
     */
    virtual void DrawImage(Point topLeft, Point bottomRight, char** image) = 0;

    /**
     * @brief Writes text at the specified position.
     * @param position Coordinates where the text should be written.
     * @param text Pointer to the text string.
     */
    virtual void WriteText(Point position, char* text) = 0;
};
