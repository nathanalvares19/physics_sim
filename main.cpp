#include <iostream>
#include <string>
#include "raylib.h"
#include "raymath.h"

int main()
{
    // window settings
    int windowWidth = 1000;
    int windowHeight = 500;
    std::string windowTitle = "Nathan";
    int windowFPS = 60;

    InitWindow(windowWidth, windowHeight, windowTitle.c_str());
    SetTargetFPS(windowFPS);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        int posX = windowWidth / 2;
        int posY = windowHeight / 2;

        int width = 100;
        int height = 100;

        DrawRectangle(posX, posY, width, height, BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}