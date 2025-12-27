#pragma once

#include "body.h"

inline void resolveCollision(
    Body *a,
    Body *b,
    const Vec2 &normal)
{
    // relative velocity
    Vec2 rv = b->velocity - a->velocity; // a at rest

    // velocity along the normal
    float velAlongNormal = rv.dot(normal);

    // do nothing if separating - b moving away from a
    if (velAlongNormal > 0.0f)
    {
        return;
    }

    // restitution
    const float restitution = 0.3f; // less bouncy to prevent sticking

    // impulse scalar - change in momentum
    float j = -(1.0f + restitution) * velAlongNormal;
    j /= (a->inverse_mass + b->inverse_mass);

    Vec2 impulse = normal * j;

    // apply impulse - a collides with b
    if (!a->is_static)
    {
        a->velocity -= impulse * a->inverse_mass;
    }

    if (!b->is_static)
    {
        b->velocity += impulse * b->inverse_mass;
    }
}
