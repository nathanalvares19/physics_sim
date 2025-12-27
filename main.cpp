#include "raylib.h"
#include "math/vec2.h"
#include "physics/body.h"
#include "physics/world.h"

int main()
{
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "2D Physics Engine - Box Scene");
    SetTargetFPS(60);

    World world;

    const float WALL_THICKNESS = 10.0f;

    Body bottomWall(
        Vec2(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT - WALL_THICKNESS / 2.0f),
        SCREEN_WIDTH,
        WALL_THICKNESS,
        0.0f);

    Body topWall(
        Vec2(SCREEN_WIDTH / 2.0f, WALL_THICKNESS / 2.0f),
        SCREEN_WIDTH,
        WALL_THICKNESS,
        0.0f);

    Body leftWall(
        Vec2(WALL_THICKNESS / 2.0f, SCREEN_HEIGHT / 2.0f),
        WALL_THICKNESS,
        SCREEN_HEIGHT,
        0.0f);

    Body rightWall(
        Vec2(SCREEN_WIDTH - WALL_THICKNESS / 2.0f, SCREEN_HEIGHT / 2.0f),
        WALL_THICKNESS,
        SCREEN_HEIGHT,
        0.0f);

    world.addBody(&bottomWall);
    world.addBody(&topWall);
    world.addBody(&leftWall);
    world.addBody(&rightWall);

    // --- Dynamic balls ---
    Body ball1(Vec2(400.0f, 100.0f), 20.0f, 1.0f);
    Body ball2(Vec2(430.0f, 50.0f), 20.0f, 1.0f);
    Body heavyBall(Vec2(370.0f, 10.0f), 25.0f, 5.0f);

    world.addBody(&ball1);
    world.addBody(&ball2);
    world.addBody(&heavyBall);

    const float dt = 1.0f / 60.0f;

    while (!WindowShouldClose())
    {
        world.step(dt);

        BeginDrawing();
        ClearBackground(BLACK);

        for (Body *body : world.bodies)
        {
            Color color = body->is_static ? DARKGRAY : WHITE;

            if (body->shape_type == ShapeType::Circle)
            {
                DrawCircle(
                    (int)body->position.x,
                    (int)body->position.y,
                    body->radius,
                    color);
            }
            else if (body->shape_type == ShapeType::Rectangle)
            {
                DrawRectangle(
                    (int)(body->position.x - body->width / 2.0f),
                    (int)(body->position.y - body->height / 2.0f),
                    (int)body->width,
                    (int)body->height,
                    color);
            }
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
