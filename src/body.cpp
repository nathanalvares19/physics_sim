#include "globals.h"
#include "body.h"

// body constructor
Body::Body(double xi, double yi, double v) : x(xi), y(yi), velocity(v)
{
}

// update location based on gravity
void Body::move()
{
    // update y location (calculate displacement every instant)
    y += velocity * dt + 0.5 * g * dt * dt;

    // update velocity
    velocity = velocity + g * dt;
}
