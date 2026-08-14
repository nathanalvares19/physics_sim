#pragma once

#include <string>
#include "raylib.h"

class Window
{
public:
    // window props
    int Width;
    int Height;
    std::string windowTitle;
    int windowFPS;

    // window constructor
    Window(int w, int h, std::string title, int fps);

    // initialize window
    void init_window(void);

    // close window
    void close_window(void);
};