#include <iostream>

#include "raylib.h"
#include "raymath.h"
#include "window.h"
#include "body.h"
#include "globals.h"

int main()
{
    // create body
    Body body(1, {static_cast<double>(window.width) / 2, height / 2 + 100});

    // drawing scene
    while (!WindowShouldClose())
    {
        // begin drawing
        BeginDrawing();
        ClearBackground(WHITE);

        DrawLineV({0, static_cast<float>(height / 2 + 100 - height / 2)}, {static_cast<float>(window.width), static_cast<float>(height / 2 + 100 - height / 2)}, BLACK);

        // main drawing logic
        body.move();
        DrawRectangle(body.position.x - width / 2, body.position.y - height / 2, width, height, RED);

        // end drawing
        EndDrawing();
    }

    // close window
    window.close();

    return 0;
}