#pragma once

#include <string>
#include "raylib.h"

class Window
{
public:
    int width;
    int height;
    std::string title;
    int fps;

    Window(int w, int h, std::string title, int fps);

    void close(void);
};