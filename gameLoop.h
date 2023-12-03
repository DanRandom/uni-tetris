#ifndef GAMELOOP_H
#define GAMELOOP_H
#include "raylib.h"
#include "startScreen.h"
#include "endScreen.h"
#include "ScoringObserver.h"

const int width = 10;
const int height = 20;
const int tileSize = 40;

class gameLoop
{
private:
    int gameGrid[width][height];
    int score;
    bool rowIsFilled;
    Screen* currentScreen;
    StartScreen startScreen;
    EndScreen endScreen;
    ScoringObserver scoringObserver;
public:
    gameLoop();
    ~gameLoop();

    void runGame();
    void clearFullRows();
    bool isRowFull(int row);
};
#endif
