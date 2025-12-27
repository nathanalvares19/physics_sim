#pragma once
#include "../math/vec2.h"

struct Body
{
    Vec2 position;
    Vec2 velocity;
    Vec2 force;
    float mass;
    float invMass;

    Body(const Vec2 &pos, float m)
        : position(pos), velocity(0, 0), force(0, 0), mass(m)
    {
        invMass = (m > 0.0f) ? 1.0f / m : 0.0f;
    }
};
