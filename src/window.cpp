#include "window.h"
#include "raylib.h"

// window constructor
Window::Window(int w, int h, std::string title, int fps) : windowWidth(w), windowHeight(h), windowTitle(title), windowFPS(fps)
{
}

// initialize window
void Window::init_window(void)
{
    InitWindow(windowWidth, windowHeight, windowTitle.c_str());
    SetTargetFPS(windowFPS);
}

// initialize window
void Window::close_window(void)
{
    CloseWindow();
}
