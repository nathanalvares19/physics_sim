#include "raylib.h"
#include "math/vec2.h"
#include "physics/body.h"
#include "physics/world.h"

int main()
{
    // window initialisation
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Nathan's Window");
    SetTargetFPS(60);

    // scene setup
    World world;
    bool paused = false;

    // main game loop
    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_P))
        {
            paused = !paused;
        }

        if (IsKeyPressed(KEY_R))
        {
            world = World();
        }

        float dt = GetFrameTime();

        if (!paused)
        {
            world.step(dt);
        }

        BeginDrawing();
        ClearBackground(WHITE);

        DrawCircle(
            (int)world.body.position.x,
            (int)world.body.position.y,
            10,
            RED);

        DrawText("Single particle under gravity", 10, 10, 20, BLACK);
        DrawText("P: Pause | R: Reset", 10, 40, 20, BLACK);

        if (paused)
        {
            DrawText("PAUSED", 700, 20, 20, BLACK);
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
