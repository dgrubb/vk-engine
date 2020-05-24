// File: Window.cc
// Author: dgrubb
// Date: 24/05/2020
//
// Handles interfacing with the the window context which provides
// display output and captures incoming key/mouse input events.

// Implementation include
#include "Window.h"

// C++ Library headers
#include <string>

// Third-party includes
#include <SDL2/SDL.h>

// Project includes
#include "util/Log.h"

Window::Window(std::string name, int width, int height)
  : window(SDL_CreateWindow(name.c_str(),
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            width, height,
            SDL_WINDOW_OPENGL),
    SDL_DestroyWindow)
{
}

bool Window::GetFullscreen()
{
    return true;
}

void Window::SetFullscreen(bool fullscreen)
{
}

Window::~Window()
{
}
