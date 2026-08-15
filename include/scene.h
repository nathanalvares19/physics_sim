#pragma once

#include <vector>
#include "raylib.h"
#include "body.h"

class Scene
{
public:
    std::vector<Body> bodies;

    void add_body(Body body);
    void check_collisions();
};