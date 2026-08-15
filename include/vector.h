#pragma once

class Vec2
{
public:
    double x;
    double y;

    Vec2(double x, double y);

    Vec2 operator+(Vec2 other);
    Vec2 operator-(Vec2 other);
};