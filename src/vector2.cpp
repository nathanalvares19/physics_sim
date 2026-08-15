#include "vector2.h"

// vector constructor
Vec2::Vec2(double x, double y) : x(x), y(y) {}

// dot product
double Vec2::dot(Vec2 other)
{
    return x * other.x + y * other.y;
}
