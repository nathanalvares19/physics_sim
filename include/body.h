#pragma once

class Body
{
public:
    double x;
    double y;
    double velocity;

    Body(double xi, double yi, double v);

    void move();
};