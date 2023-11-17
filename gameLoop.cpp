#include "raylib.h"
#include "gameLoop.h"
#include "shape.h"
#include "endScreen.h"
#include <iostream>
#include <random>
#include <algorithm>

gameLoop::gameLoop() {
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            gameGrid[x][y] = 0;
        }
    }
    score = 0;
}

gameLoop::~gameLoop() {

}

Shape createShape() {
    Color colors[] = {RED, BLUE, GREEN, YELLOW, PURPLE, ORANGE, PINK};
    return Shape(rand() % 7, colors[rand() % 7]);
}

void gameLoop::clearFullRows() {
    //Check for a full row
    for (int y = height - 1; y >= 0; --y) {
        bool isRowFull = true;
        for (int x = 0; x < width; ++x) {
            if (gameGrid[x][y] == 0) {
                isRowFull = false;
                break;
            }
        }

        if (isRowFull) {
            // Clear the full row
            for (int i = y; i > 0; --i) {
                for (int x = 0; x < width; ++x) {
                    gameGrid[x][i] = gameGrid[x][i - 1];
                }
            }
            // Set the top row to empty
            for (int x = 0; x < width; ++x) {
                gameGrid[x][0] = 0;
            }
            // Move the shapes above the cleared row down
            for (int i = y - 1; i >= 0; --i) {
                for (int x = 0; x < width; ++x) {
                    gameGrid[x][i + 1] = gameGrid[x][i];
                }
            }
            score += 10;
        }
    }
}



void gameLoop::game()
{
    EndScreen end;
    const float movementInterval = 500.0f;
    const float fallingInterval = 500.0f;
    float elapsedMoveTime = 0.0f;
    float elapsedFallTime = 0.0f;
    bool rotateKeyPressed = false;


    Shape shape = createShape();
    Shape prevShape = shape;
    bool drawOldShape = false;
    bool fastFall = false;

    SetTargetFPS(60);
    

    while (!WindowShouldClose())
    {
        float deltaTime = GetFrameTime() * 1000;
        elapsedMoveTime += deltaTime;
        elapsedFallTime += deltaTime;

        if(shape.hasTouchedGround(gameGrid)) {
            shape.updateGrid(gameGrid);
            clearFullRows();
            prevShape = shape;
            drawOldShape = true;
            shape = createShape();
        }
        //Check if the game is over
        if (shape.hasTouchedGround(gameGrid)) {
            end.displayEnd();
        }

        if (IsKeyDown(KEY_DOWN)) {
            fastFall = true;
        } else {
            fastFall = false;
        }

        if (elapsedFallTime >= fallingInterval) {
            if (!shape.hasTouchedGround(gameGrid)) {
                shape.move(0, 1, gameGrid, fastFall);
            }
            elapsedFallTime = 0.0f;
        }
        
    
        if (IsKeyDown(KEY_RIGHT)) {
            if (elapsedMoveTime >= movementInterval) {
                shape.move(1, 0, gameGrid, fastFall);
                elapsedMoveTime = 0.0f;
            }
        }
        if (IsKeyDown(KEY_LEFT)) {
            if (elapsedMoveTime >= movementInterval) {
                shape.move(-1, 0, gameGrid, fastFall);
                elapsedMoveTime = 0.0f;
            }
        }

        if (IsKeyPressed(KEY_UP)) {
            rotateKeyPressed = true;
        } else {
            rotateKeyPressed = false;
        }

        if (rotateKeyPressed) {
            shape.rotate();
        }

        


        
        BeginDrawing();

            ClearBackground(BLACK);

            // Draw the grid
            for (int x = 0; x < width; x++) {
                for (int y = 0; y < height; y++) {
                    DrawRectangle(x * tileSize, y * tileSize, tileSize, tileSize, BLACK);
                }
            }

            // Draw the updated grid with the new shapes
            for (int x = 0; x < width; x++) {
                for (int y = 0; y < height; y++) {
                    int shapeType = gameGrid[x][y];
                    if (shapeType != 0) {
                        DrawRectangle(x * tileSize, y * tileSize, tileSize, tileSize, WHITE);
                    }
                }
            }
            //Draw the falling shape
            if(drawOldShape) {
                prevShape.draw(tileSize);
                drawOldShape = false;
            } else {
                shape.draw(tileSize);
            }
            //Draw the score
            DrawRectangleLinesEx({0, 0, width * tileSize, height * tileSize}, 2, WHITE);
            DrawText(TextFormat("Score: %d", score), width * tileSize + 10, 10, 20, WHITE);

        EndDrawing();
    
    }

    
    
    CloseWindow();

}