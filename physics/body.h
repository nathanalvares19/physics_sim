#pragma once
#include "../math/vec2.h"
#include <string>
using namespace std;

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
    float mass;
    float invMass;
    bool onGround = false;

    // type
    ShapeType shape;

    // for circular body
    float radius;

    // for rectangular body
    float width;
    float height;

    Body(const Vec2 &pos, float m, float r)
        : position(pos), velocity(0, 0), force(0, 0), mass(m), shape(ShapeType::Circle), radius(r), width(0.0f), height(0.0f)
    {
        invMass = (m > 0.0f) ? 1.0f / m : 0.0f;
    }

    Body(const Vec2 &pos, float m, float w, float h)
        : position(pos), velocity(0, 0), force(0, 0), mass(m), shape(ShapeType::Rectangle), radius(0), width(w), height(h)
    {
        invMass = (m > 0.0f) ? 1.0f / m : 0.0f;
    }
};
