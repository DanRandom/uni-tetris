#include "raylib.h"
#include "endScreen.h"
#include "gameLoop.h"

EndScreen::EndScreen() {
    
}

EndScreen::~EndScreen() {

}

void EndScreen::displayEnd() {

    const char message[128] = "GAME\nOVER";

    int framesCounter = 0;

    SetTargetFPS(60);

    gameLoop gm;

    while (!WindowShouldClose())
    {
        framesCounter++;
        if (IsKeyPressed(KEY_ENTER)) gm.game();
        
        BeginDrawing();

            ClearBackground(BLACK);

            DrawText(TextSubtext(message, 0, framesCounter/10), 150, 200, 100, MAROON);

            DrawText("PRESS [ENTER] to RESTART THE GAME!", 100, 500, 20, LIGHTGRAY);
            DrawText("PRESS [ESC] to QUIT!", 100, 550, 20, LIGHTGRAY);

        EndDrawing();
    }
    CloseWindow();
}