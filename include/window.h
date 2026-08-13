#pragma once

#include <string>
#include "raylib.h"

class Window
{
public:
    // window props
    int windowWidth;
    int windowHeight;
    std::string windowTitle;
    int windowFPS;

public:
    // window constructor
    Window(int w, int h, std::string title, int fps);

    // initialize window
    void init_window(void);

    // close window
    void close_window(void);
};