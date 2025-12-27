#include "raylib.h"
#include "raymath.h"
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

    // world setup
    World world;
    Body ball(Vec2(400, 50), 1.0f, 20.0f);
    world.add(ball);
    Body ground(Vec2(0, 400), 0.0f, 800.0f, 50.0f);
    world.add(ground);

    // pause logic
    bool paused = false;

    float timeScale = 1.0f;
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
            Body ball(Vec2(400, 50), 1.0f, 20.0f);
            world.add(ball);
            Body ground(Vec2(0, 400), 0.0f, 800.0f, 50.0f);
            world.add(ground);
        }

        float dt = GetFrameTime() * timeScale;

        if (IsKeyPressed(KEY_RIGHT))
        {
            timeScale *= 2;
        }
        else if (IsKeyPressed(KEY_LEFT))
        {
            timeScale *= 0.5f;
        }

        timeScale = Clamp(timeScale, 0.25f, 8.0f);

        if (!paused)
        {
            world.step(dt);
        }

        BeginDrawing();
        ClearBackground(WHITE);

        DrawText("Ground Collision Detection", 10, 10, 20, BLACK);
        DrawText(
            TextFormat("Time Scale: x%.2f", timeScale),
            620, 10, 20, BLACK);

        if (paused)
        {
            DrawText("PAUSED", 700, 30, 20, BLACK);
        }

        DrawCircle(world.bodies[0].position.x, world.bodies[0].position.y, world.bodies[0].radius, RED);
        DrawRectangle(world.bodies[1].position.x, world.bodies[1].position.y, world.bodies[1].width, world.bodies[1].height, GREEN);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
