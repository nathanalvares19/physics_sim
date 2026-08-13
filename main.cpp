#include <iostream>
#include "raylib.h"
#include "raymath.h"
#include "window.h"

int main()
{
    // create a window
    Window window(1000, 500, "Nathan", 60);

    // initialize window
    window.init_window();

    // drawing loop
    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(LIME);

        int posX = windowWidth / 2;
        int posY = windowHeight / 2;

        int width = 100;
        int height = 100;

        DrawRectangle(posX, posY, width, height, BLACK);

        EndDrawing();
    }

    // close window
    window.close_window();

    return 0;
}