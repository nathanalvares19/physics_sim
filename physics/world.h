#pragma once

#include <vector>
#include "body.h"
#include "collision.h"
#include "resolve.h"
#include "position_correction.h"

struct World
{
    std::vector<Body *> bodies;
    Vec2 gravity;

    World() : gravity(0.0f, 500.0f) {}

    void addBody(Body *body)
    {
        bodies.push_back(body);
    }

    void step(float dt)
    {
        // multiple collision resolution
        const int COLLISION_ITERATIONS = 8;

        // apply force - for now only gravity
        for (Body *body : bodies)
        {
            if (body->is_static)
            {
                continue;
            }

            // apply gravity force on body
            body->force = gravity * body->mass;

            // calculate kinematic factors for a small time step dt
            Vec2 acceleration = body->force * body->inverse_mass;
            body->velocity += acceleration * dt;

            // apply damping to simulate air resistance
            body->velocity *= 0.99f;

            body->position += body->velocity * dt;

            // remove gravity otherwise it will accumulate
            body->force = Vec2(0.0f, 0.0f);
        }

        // collision detection + resolution
        for (int k = 0; k < COLLISION_ITERATIONS; ++k)
        {
            for (size_t i = 0; i < bodies.size(); ++i)
            {
                for (size_t j = i + 1; j < bodies.size(); ++j)
                {

                    Body *a = bodies[i];
                    Body *b = bodies[j];

                    Vec2 normal;
                    float penetration;

                    if (detectCollision(a, b, normal, penetration)) // detect
                    {
                        resolveCollision(a, b, normal);
                        positionalCorrection(a, b, normal, penetration);
                    }
                }
            }
        }
    }
};