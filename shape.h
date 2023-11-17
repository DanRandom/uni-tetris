#ifndef SHAPE_H
#define SHAPE_H
#include "raylib.h"
#include "gameLoop.h"

class Shape
{
private:
    int shapeType;
    int shape[4][4];
    Color shapeColor;
    int grid[width][height];
    int posX;
    int posY;
public:
    Shape(int type, Color color);
    Shape(const Shape& other);
    ~Shape();

    void draw(int tileSize);
    void move(int x, int y, int gameGrid[width][height], bool isDownPressed);
    bool hasTouchedGround(int gameGrid[width][height]);
    void updateGrid(int gameGrid[width][height]);
    void rotate();
    bool isWithinBounds();
    int getType();
};
#endif