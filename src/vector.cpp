#include "vector.h"

// vector constructor
Vec2::Vec2(double x, double y) : x(x), y(y) {}

// vector addition
Vec2 Vec2::operator+(Vec2 other)
{
    return Vec2(x + other.x, y + other.y);
}

// vector subtraction
Vec2 Vec2::operator-(Vec2 other)
{
    return Vec2(x - other.x, y - other.y);
}
