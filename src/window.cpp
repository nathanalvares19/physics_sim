#include "window.h"
#include "raylib.h"

// window constructor
Window::Window(int w, int h, std::string title, int fps) : width(w), height(h), title(title), fps(fps)
{
    InitWindow(this->width, this->height, this->title.c_str());
    SetTargetFPS(this->fps);
}

// initialize window
void Window::close(void)
{
    CloseWindow();
}
