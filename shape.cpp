#include "raylib.h"
#include "shape.h"
#include "gameLoop.h"
#include <iostream>

Shape::Shape(int type, Color color) {
        shapeType = type;
        shapeColor = color;

        //Fill the shape with zeros
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                shape[i][j] = 0;
            }
        }

        // Initialize the shape data
        switch (shapeType) {
            case 0: // I shape
                shape[0][1] = shape[1][1] = shape[2][1] = shape[3][1] = 1;
                break;
            case 1: // J shape
                shape[0][2] = shape[1][2] = shape[2][2] = shape[2][1] = 1;
                break;
            case 2: // L shape
                shape[0][1] = shape[1][1] = shape[2][1] = shape[2][2] = 1;
                break;
            case 3: // O shape
                shape[1][1] = shape[1][2] = shape[2][1] = shape[2][2] = 1;
                break;
            case 4: // S shape
                shape[1][1] = shape[1][2] = shape[2][2] = shape[2][3] = 1;
                break;
            case 5: // T shape
                shape[1][1] = shape[1][2] = shape[1][3] = shape[2][2] = 1;
                break;
            case 6: // Z shape
                shape[1][2] = shape[1][3] = shape[2][1] = shape[2][2] = 1;
                break;
            default:
                break;
        }
        // Set the starting position
        posX = 0;
        posY = 0;

    }

    Shape::Shape(int type, Color color, int x, int y) {
        shapeType = type;
        shapeColor = color;

        //Fill the shape with zeros
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                shape[i][j] = 0;
            }
        }

        // Initialize the shape data
        switch (shapeType) {
            case 0: // I shape
                shape[0][1] = shape[1][1] = shape[2][1] = shape[3][1] = 1;
                break;
            case 1: // J shape
                shape[0][2] = shape[1][2] = shape[2][2] = shape[2][1] = 1;
                break;
            case 2: // L shape
                shape[0][1] = shape[1][1] = shape[2][1] = shape[2][2] = 1;
                break;
            case 3: // O shape
                shape[1][1] = shape[1][2] = shape[2][1] = shape[2][2] = 1;
                break;
            case 4: // S shape
                shape[1][1] = shape[1][2] = shape[2][2] = shape[2][3] = 1;
                break;
            case 5: // T shape
                shape[1][1] = shape[1][2] = shape[1][3] = shape[2][2] = 1;
                break;
            case 6: // Z shape
                shape[1][2] = shape[1][3] = shape[2][1] = shape[2][2] = 1;
                break;
            default:
                break;
        }
        // Set the starting position
        posX = x;
        posY = y;

    }

    // Constructor for copying a shape
    Shape::Shape(const Shape& other) {
        shapeType = other.shapeType;
        shapeColor = other.shapeColor;
        posX = other.posX;
        posY = other.posY;

        // Copy the shape data
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                shape[i][j] = other.shape[i][j];
            }
        }
    }




    Shape::~Shape() {

    }

int Shape::getType() {
    return shapeType;
}

int Shape::getPositionX() {
    return posX;
}

int Shape::getPositionY() {
    return posY;
}

Color Shape::getColor() {
    return shapeColor;
}

void Shape::draw(int tileSize) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            // Check if the cell is filled
            if (shape[i][j] == 1) {
                // Transform the shape coords to the screen coords
                int screenX = (posX + j) * tileSize;
                int screenY = (posY + i) * tileSize;

                // Draw if within screen
                if (screenX >= 0 && screenX < GetScreenWidth() && screenY >= 0 && screenY < GetScreenHeight()) {
                    DrawRectangle(screenX, screenY, tileSize, tileSize, shapeColor);
                }
            }
        }
    }
}


void Shape::move(int x, int y, int gameGrid[width][height], bool isDownPressed) {
    int newX = posX + x;
    int newY = posY + y;

    // Check if the new position is valid (within boundaries and no collisions)
    bool collision = hasTouchedGround(gameGrid);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (shape[i][j] == 1) {
                int gridX = newX + j;
                int gridY = newY + i;

                if (!isWithinBounds(gridX, gridY) || gameGrid[gridX][gridY] != 0) {
                    collision = true;
                    break;
                }
            }
        }
        if (collision) {
            break;
        }
    }

    if (!collision) {
        posX = newX;
        posY = newY;

        // Speed up the falling
        if (isDownPressed) {
            move(0, 1, gameGrid, false);
        }
    }
}


void Shape::rotate() {
    // Save the current shape
    int tempShape[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            tempShape[i][j] = shape[i][j];
        }
    }

    //Rotate 90
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            shape[i][j] = tempShape[3 - j][i];
        }
    }

    if (!isWithinBounds()) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                shape[i][j] = tempShape[i][j];
            }
        }
    }
}

bool Shape::isWithinBounds(int x, int y) {
    return (x >= 0 && x < width && y >= 0 && y < height);
}

bool Shape::isWithinBounds() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (shape[i][j] == 1) {
                int newX = posX + j;
                int newY = posY + i;

                if (!isWithinBounds(newX, newY)) {
                    return false;
                }
            }
        }
    }
    return true;
}

void Shape::updateGrid(int gameGrid[width][height]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int gridX = posX + j;
            int gridY = posY + i;

            if (shape[i][j] == 1 && isWithinBounds(gridX, gridY)) {
                gameGrid[gridX][gridY] = (shapeType != 0) ? shapeType : (shapeType + 8);
            }
        }
    }
}

bool Shape::hasTouchedGround(int gameGrid[width][height]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (shape[i][j] == 1) {
                int newY = posY + i + 1;
                int newX = posX + j;
                // Check if it's against the ground or touches an existing shape
                if (newY >= height || gameGrid[newX][newY] != 0) {
                    return true;
                }

                // Check if it's against the wall or touches an existing shape upon spawn (gameover)
                if (newX < 0 || newX >= width || gameGrid[newX][newY - 1] != 0 || (posY == 0 && gameGrid[newX][newY] != 0)) {
                    return true; 
                }
            }
        }
    }

    return false; 
}