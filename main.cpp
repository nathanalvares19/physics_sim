#include <iostream>
#include "raylib.h"
#include "raymath.h"
#include "window.h"

Window window(1000, 500, "Nathan", 30);

double width = 300;
double height = 100;

class Body
{
public:
    double x;
    double y;
    double vel;
    Body(double xi, double yi, double v)
    {
        x = xi;
        y = yi;
        vel = v;
    }

    void update()
    {
        if (y + height > window.Height)
        {
            vel = (-1) * vel;
            y = window.Height - height;
            return;
        }
        vel = vel + 9.81 * 0.5;
        y = y + (vel) * (0.5) + (0.5) * (9.81) * (0.5) * (0.5);
    }
};

int main()
{

    // initialize window
    window.init_window();

    double time = 0;

    Body body(window.Width / 2 - width / 2, 0, 0);

    double xi = window.Width / 2 - width / 2;
    double yi = 0;

    // drawing loop
    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(LIME);

        if (IsKeyPressed(KEY_R))
        {
            DrawRectangle(body.x, 0, width, height, BLACK);
            body.y = 0;
            body.vel = 0;
        }
        else
        {
            DrawRectangle(body.x, body.y, width, height, BLACK);
        }

        body.update();

        EndDrawing();
    }

    // close window
    window.close_window();

    return 0;
}