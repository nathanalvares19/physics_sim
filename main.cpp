#include <iostream>
#include "raylib.h"
#include "raymath.h"
#include "window.h"
#include "body.h"
#include "globals.h"
#include "scene.h"
#include "state_utils.h"

int main()
{
    // create bodies at random positions
    int num_of_bodies = 100;
    std::vector<Vec2> initial_positions;
    for (int i = 0; i < num_of_bodies; i++)
    {
        initial_positions.push_back(random_position(radius));
    }

    std::vector<Vec2> initial_velocities;
    for (int i = 0; i < num_of_bodies; i++)
    {
        initial_velocities.push_back(random_velocity(max_speed));
    }

    // create scene
    Scene scene1;
    for (int i = 0; i < num_of_bodies; i++)
    {
        // add body
        double mass = 1;
        Vec2 pos = {initial_positions[i].x, initial_positions[i].y};
        Vec2 vel = {initial_velocities[i].x, initial_velocities[i].y};
        Body body(mass, pos, vel, {0, g});
        scene1.add_body(body);
    }

    // draw scene
    while (!WindowShouldClose())
    {
        // begin drawing
        BeginDrawing();
        ClearBackground(WHITE);

        // main drawing logic
        for (int i = 0; i < num_of_bodies; i++)
        {
            scene1.bodies[i].move();
            DrawCircle(scene1.bodies[i].position.x, scene1.bodies[i].position.y, radius, RED);
        }

        scene1.check_collisions();

        // end drawing
        EndDrawing();
    }

    // close window
    window.close();

    return 0;
}