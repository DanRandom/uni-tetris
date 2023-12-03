#include "raylib.h"
#include "startScreen.h"
#include "gameLoop.h"

StartScreen::StartScreen() {
    
}

StartScreen::~StartScreen() {

}

void StartScreen::display() {

    const int screenWidth = tileSize * width + 250;
    const int screenHeight = tileSize * height + 100;

    InitWindow(screenWidth, screenHeight, "Tetris");

    const char message[10] = "TETRIS";

    int framesCounter = 0;

    SetTargetFPS(60);

    gameLoop gm;

    while (!WindowShouldClose())
    {
        framesCounter++;
        if (IsKeyPressed(KEY_ENTER)) gm.runGame();
        
        BeginDrawing();

            ClearBackground(BLACK);

            DrawText(TextSubtext(message, 0, framesCounter/10), 150, 200, 100, MAROON);

            DrawText("PRESS [ENTER] to START THE GAME!", 100, 300, 20, LIGHTGRAY);
            DrawText("PRESS [ESC] to QUIT!", 100, 350, 20, LIGHTGRAY);

        EndDrawing();
    }
    CloseWindow();
}