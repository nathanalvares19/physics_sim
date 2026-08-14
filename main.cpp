#include <iostream>

#include "raylib.h"
#include "raymath.h"
#include "window.h"
#include "body.h"

// rectangle dimensions
double width = 300;
double height = 100;

int main()
{
    // create window
    Window window(1000, 500, "Nathan", 30);

    // create body
    Body body(window.width / 2, height / 2, 0);

    // drawing scene
    while (!WindowShouldClose())
    {
        // begin drawing
        BeginDrawing();
        ClearBackground(WHITE);

        // reset logic
        if (IsKeyPressed(KEY_R))
        {
            body.y = 0;
            body.velocity = 0;
            DrawRectangle(body.x - width / 2, body.y - height / 2, width, height, RED);
        }
        else
        {
            // main drawing logic
            DrawRectangle(body.x - width / 2, body.y - height / 2, width, height, RED);
            body.move();
        }

        // end drawing
        EndDrawing();
    }

    // close window
    window.close();

    return 0;
}