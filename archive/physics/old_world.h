#pragma once
#include "body.h"
#include <vector>
using namespace std;

struct World
{
    vector<Body> bodies;
    Vec2 gravity;

    World() : gravity(0.0f, 500.0f) {}

    void add(const Body &body)
    {
        bodies.push_back(body);
    }

    void step(float dt)
    {
        const float groundY = 400.0f;
        const float restitution = 0.60f;
        const float restVelocity = 7.0f;

        for (Body &body : bodies)
        {
            if (body.invMass == 0.0f)
            {
                continue;
            }

            if (!body.onGround)
            {
                body.force = gravity * body.mass;
            }
            else
            {
                body.force = Vec2(0.0f, 0.0f);
            }

            Vec2 acceleration = body.force * body.invMass;

            body.position += body.velocity * dt + 0.5f * acceleration * dt * dt;
            body.velocity += acceleration * dt;

            body.force = Vec2(0.0f, 0.0f);

            if (body.shape == ShapeType::Circle)
            {
                float penetration = body.position.y + body.radius - groundY;
                body.onGround = penetration == 0.0f;
                if (penetration > 0.0f)
                {
                    body.position.y -= penetration;

                    if (abs(body.velocity.y) < restVelocity)
                    {
                        body.velocity.y = 0.0f;
                        body.position.y = groundY - body.radius;
                    }

                    float velAlongNormal = body.velocity.y;

                    if (velAlongNormal > 0.0f)
                    {
                        float e = restitution;
                        float j = -(1 + e) * velAlongNormal;
                        body.velocity.y += j * body.invMass;
                    }
                }
            }
        }
    }
};
