#pragma once

#include "raylib.h"
#include "vector.h"

class Body
{
public:
    double mass;
    Vec2 position; // COM position
    Vec2 velocity;
    Vec2 force; // apart from gravity
    Vec2 acceleration;

    Body(double m, Vec2 p, Vec2 v, Vec2 F);
    Body(double m);
    Body(double m, Vec2 p);

    void move();
};

void check_bounds_rect(Vec2 &p, Vec2 &v);
void check_bounds_circle(Vec2 &p, Vec2 &v);