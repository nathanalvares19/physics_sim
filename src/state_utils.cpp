#include "state_utils.h"

#include <random>

#include "globals.h"
#include "window.h"

static std::random_device rd;
static std::mt19937 gen(rd());

Vec2 random_position(double radius)
{
    std::uniform_real_distribution<double> x_dist(
        radius,
        static_cast<double>(window.width) - radius);

    std::uniform_real_distribution<double> y_dist(
        radius,
        static_cast<double>(window.height) - radius);

    return Vec2(x_dist(gen), y_dist(gen));
}

Vec2 random_velocity(double max_speed)
{
    std::uniform_real_distribution<double> velocity_dist(-max_speed, max_speed);

    return Vec2(
        velocity_dist(gen),
        velocity_dist(gen));
}
