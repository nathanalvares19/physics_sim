#pragma once

#include "../math/vec2.h"

enum class ShapeType
{
    Circle,
    Rectangle
};

struct Body
{
    Vec2 position;
    Vec2 velocity;
    Vec2 force;

    ShapeType shape_type;

    // Circle properties
    float radius;

    // Rectangle properties
    float width;
    float height;

    float mass;
    float inverse_mass;

    bool is_static; // immovable or not

    // Circle constructor
    Body(const Vec2 &pos, float r, float m)
        : position(pos), radius(r), mass(m), shape_type(ShapeType::Circle),
          width(0.0f), height(0.0f)
    {
        velocity = Vec2(0.0f, 0.0f);
        force = Vec2(0.0f, 0.0f);

        if (mass <= 0.0f)
        {
            is_static = true;
            inverse_mass = 0.0f;
        }
        else
        {
            is_static = false;
            inverse_mass = 1.0f / mass;
        }
    }

    // Rectangle constructor
    Body(const Vec2 &pos, float w, float h, float m)
        : position(pos), width(w), height(h), mass(m), shape_type(ShapeType::Rectangle),
          radius(0.0f)
    {
        velocity = Vec2(0.0f, 0.0f);
        force = Vec2(0.0f, 0.0f);

        if (mass <= 0.0f)
        {
            is_static = true;
            inverse_mass = 0.0f;
        }
        else
        {
            is_static = false;
            inverse_mass = 1.0f / mass;
        }
    }
};
