#include "scene.h"
#include "body.h"
#include "globals.h"
#include <cmath>

// add body function
void Scene::add_body(Body body)
{
    bodies.push_back(body);
}

// check collisions
void Scene::check_collisions()
{
    int size = bodies.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            Body &a = bodies[i];
            Body &b = bodies[j];

            // distance between centers (final - initial)
            double dx = b.position.x - a.position.x;
            double dy = b.position.y - a.position.y;

            double distance = sqrt(dx * dx + dy * dy);

            // collision condition
            if (distance == 0.0 || distance > 2 * radius)
            {
                continue;
            }

            // collision normal (from a to b)
            double nx = dx / distance;
            double ny = dy / distance;
            Vec2 normal = {nx, ny};
            Vec2 tangent = {-ny, nx};

            // fix overlap
            double overlap = 2 * radius - distance;

            a.position.x -= nx * overlap / 2.0;
            a.position.y -= ny * overlap / 2.0;

            b.position.x += nx * overlap / 2.0;
            b.position.y += ny * overlap / 2.0;

            // flip velocities
            Vec2 u1 = a.velocity;
            Vec2 u2 = b.velocity;

            // normal - tangent components
            double normal_u1 = u1.dot(normal);
            double tangent_u1 = u1.dot(tangent);

            double normal_u2 = u2.dot(normal);
            double tangent_u2 = u2.dot(tangent);

            if (normal_u2 - normal_u1 > 0)
            {
                continue;
            }

            // new normal components
            double normal_v1 =
                (a.mass * normal_u1 + b.mass * normal_u2 - b.mass * e * (normal_u1 - normal_u2)) /
                (a.mass + b.mass);

            double normal_v2 =
                (a.mass * normal_u1 + b.mass * normal_u2 + a.mass * e * (normal_u1 - normal_u2)) /
                (a.mass + b.mass);

            // update velocities
            a.velocity.x = normal_v1 * normal.x + tangent_u1 * tangent.x;
            a.velocity.y = normal_v1 * normal.y + tangent_u1 * tangent.y;

            b.velocity.x = normal_v2 * normal.x + tangent_u2 * tangent.x;
            b.velocity.y = normal_v2 * normal.y + tangent_u2 * tangent.y;
        }
    }
}
