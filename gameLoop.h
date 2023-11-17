#ifndef GAMELOOP_H
#define GAMELOOP_H
#include "raylib.h"

const int width = 10;
const int height = 20;
const int tileSize = 40;

class gameLoop
{
private:
    int gameGrid[width][height];
    int score;
public:
    gameLoop();
    ~gameLoop();

    void game();
    void clearFullRows();
    bool isRowFull(int row);
};
#endif
