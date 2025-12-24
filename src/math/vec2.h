#pragma once

#include <cmath>

struct Vec2
{
    // position coordinates
    float x, y;

    // constructors
    Vec2() : x(0.0f), y(0.0f) {}
    Vec2(float x_, float y_) : x(x_), y(y_) {}

    // operations
    Vec2 operator+(const Vec2 &other) const
    {
        return Vec2(x + other.x, y + other.y);
    }

    Vec2 operator-(const Vec2 &other) const
    {
        return Vec2(x - other.x, y - other.y);
    }

    Vec2 operator*(float scalar) const
    {
        return Vec2(x * scalar, y * scalar);
    }

    Vec2 &operator+=(const Vec2 &other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vec2 &operator-=(const Vec2 &other)
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Vec2 &operator*=(float scalar)
    {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    // dot product
    float dot(const Vec2 &other) const
    {
        return x * other.x + y * other.y;
    }

    // magnitude
    float length() const
    {
        return std::sqrt(x * x + y * y);
    }

    // normalise
    Vec2 normalised() const
    {
        float len = length();
        if (len == 0.0f)
        {
            return Vec2(0.0f, 0.0f);
        }
        return Vec2(x / len, y / len);
    }
};
