#include "globals.h"
#include "window.h"

Window window(800, 800, "The Matrix", 120);

// time interval
double dt = 0.05;

// gravitational acceleration
double g = 9.81;

// coefficient of restitution
double e = 1.0;

// rectangle dimensions
double width = 50;
double height = 50;

// circle dimensions
double radius = 35;

// max speed
double max_speed = 200;