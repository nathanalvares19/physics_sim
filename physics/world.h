#pragma once
#include "body.h"

struct World
{
    Body body;
    Vec2 gravity;

    World()
        : body(Vec2(400, 50), 1.0f), gravity(0.0f, 500.0f) {}

    void step(float dt)
    {
        body.force = gravity * body.mass;

        Vec2 acceleration = body.force * body.invMass;

        body.velocity += acceleration * dt;
        body.position += body.velocity * dt;

        body.force = Vec2(0, 0);
    }
};
