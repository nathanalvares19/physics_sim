#pragma once

#include "body.h"

inline void positionalCorrection(
    Body *a,
    Body *b,
    const Vec2 &normal,
    float penetration)
{
    // percentage of penetration to correct (tuning parameter)
    const float percent = 1.0f;

    // small allowance to prevent jitter
    const float slop = 0.3f;

    float correctionMagnitude =
        std::max(penetration - slop, 0.0f) /
        (a->inverse_mass + b->inverse_mass) * percent;

    Vec2 correction = normal * correctionMagnitude;

    if (!a->is_static)
        a->position -= correction * a->inverse_mass;

    if (!b->is_static)
        b->position += correction * b->inverse_mass;
}
