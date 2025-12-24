#pragma once

#include "body.h"
#include <algorithm>

inline bool circleCircleCollision(
    Body *a,
    Body *b,
    Vec2 &normal,
    float &penetration)
{
    Vec2 diff = b->position - a->position; // vector joining centers
    float distance = diff.length();
    float radiusSum = a->radius + b->radius;

    // no collision
    if (distance >= radiusSum)
    {
        return false;
    }

    // same position
    if (distance == 0.0f)
    {
        normal = Vec2(1.0f, 0.0f);
        penetration = radiusSum;
    }
    else
    {
        normal = diff * (1.0f / distance); // normalized
        penetration = radiusSum - distance;
    }

    return true;
}

inline bool circleRectCollision(
    Body *circle,
    Body *rect,
    Vec2 &normal,
    float &penetration)
{
    // AABB half extents
    float halfWidth = rect->width * 0.5f;
    float halfHeight = rect->height * 0.5f;

    // Vector from rect center to circle center
    Vec2 diff = circle->position - rect->position;

    // Clamp point to edges of the AABB
    Vec2 clamped;
    clamped.x = std::max(-halfWidth, std::min(halfWidth, diff.x));
    clamped.y = std::max(-halfHeight, std::min(halfHeight, diff.y));

    // Closest point on AABB to circle center (in world space)
    Vec2 closest = rect->position + clamped;

    // Vector from closest point to circle center
    Vec2 delta = circle->position - closest;
    float distSq = delta.x * delta.x + delta.y * delta.y;
    float radiusSq = circle->radius * circle->radius;

    // No collision
    if (distSq >= radiusSq)
    {
        return false;
    }

    // Collision occurred
    float dist = std::sqrt(distSq);

    if (dist > 0.0001f)
    {
        // Normal points from closest point toward circle center
        normal = delta * (1.0f / dist);
        penetration = circle->radius - dist;
    }
    else
    {
        // Circle center is exactly on the edge - use the axis with smallest penetration
        float xPen = halfWidth - std::abs(diff.x);
        float yPen = halfHeight - std::abs(diff.y);

        if (xPen < yPen)
        {
            normal = (diff.x > 0) ? Vec2(1.0f, 0.0f) : Vec2(-1.0f, 0.0f);
            penetration = circle->radius + xPen;
        }
        else
        {
            normal = (diff.y > 0) ? Vec2(0.0f, 1.0f) : Vec2(0.0f, -1.0f);
            penetration = circle->radius + yPen;
        }
    }

    return true;
}

inline bool detectCollision(
    Body *a,
    Body *b,
    Vec2 &normal,
    float &penetration)
{
    if (a->shape_type == ShapeType::Circle && b->shape_type == ShapeType::Circle)
    {
        return circleCircleCollision(a, b, normal, penetration);
    }
    else if (a->shape_type == ShapeType::Circle && b->shape_type == ShapeType::Rectangle)
    {
        return circleRectCollision(a, b, normal, penetration);
    }
    else if (a->shape_type == ShapeType::Rectangle && b->shape_type == ShapeType::Circle)
    {
        bool result = circleRectCollision(b, a, normal, penetration);
        normal = normal * -1.0f; // Flip normal
        return result;
    }

    return false; // Rectangle-Rectangle not implemented
}
