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
    Shape(int type, Color color, int x, int y);
    ~Shape();
    void draw(int tileSize);
    void move(int x, int y, int gameGrid[width][height], bool isDownPressed);
    bool hasTouchedGround(int gameGrid[width][height]);
    void updateGrid(int gameGrid[width][height]);
    void rotate();
    bool isWithinBounds();
    bool isWithinBounds(int x, int y);
    int getType();
    Color getColor();
    int getPositionX();
    int getPositionY();
};
#endif