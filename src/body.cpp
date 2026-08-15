#include "globals.h"
#include "window.h"
#include "body.h"

// body constructor (general)
Body::Body(double m, Vec2 p, Vec2 v, Vec2 F) : mass(m), position(p), velocity(v), force(F), acceleration({0, g})
{
    acceleration.x += force.x / mass;
    acceleration.y += force.y / mass;
}

// body constructor (only mass and gravity)
Body::Body(double m) : mass(m), position({0, 0}), velocity({0, 0}), force({0, 0}), acceleration({0, g}) {}

// body constructor (mass and position)
Body::Body(double m, Vec2 p) : mass(m), position(p), velocity({0, 0}), force({0, 0}), acceleration({0, g}) {}

// update body state
void Body::move()
{
    // update position
    position.x += velocity.x * dt + 0.5 * acceleration.x * dt * dt;
    position.y += velocity.y * dt + 0.5 * acceleration.y * dt * dt;

    // update velocity
    velocity.x = velocity.x + acceleration.x * dt;
    velocity.y = velocity.y + acceleration.y * dt;

    // boundary check (window)
    if (position.y + height / 2 > window.height)
    {
        position.y = window.height - height / 2;
        velocity.y *= -1;
    }

    if (position.y - height / 2 < 0)
    {
        position.y = height / 2;
        velocity.y *= -1;
    }

    if (position.x + width / 2 > window.width)
    {
        position.x = window.width - width / 2;
        velocity.x *= -1;
    }

    if (position.x - width / 2 < 0)
    {
        position.x = width / 2;
        velocity.x *= -1;
    }
}
