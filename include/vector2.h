#pragma once

class Vec2
{
public:
    double x;
    double y;

    Vec2(double x, double y);

    double dot(Vec2 other);
};