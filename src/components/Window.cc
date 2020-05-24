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
    int w, h;
    SDL_GetWindowSize(window.get(), &w, &h);
    INFO("Created window [{}]: {}x{}", SDL_GetWindowTitle(window.get()), w, h);
}

// Checks the window flags to ascertain if it's fullscreen or not.
// N.b., fullscreen in this context means truly fullscreen, not whether the
// window has been scaled to overlay the whole window as determined by
// SDL_WINDOW_FULLSCREEN_DESKTOP
bool Window::GetFullscreen()
{
    return (GetWindowFlags() & SDL_WINDOW_FULLSCREEN);
}

void Window::SetFullscreen(bool fullscreen)
{
    uint32_t flags = GetWindowFlags();
    if (fullscreen)
    {
        flags |= SDL_WINDOW_FULLSCREEN;
    }
    else
    {
        flags &= ~SDL_WINDOW_FULLSCREEN;
    }
    SDL_SetWindowFullscreen(window.get(), flags);
}

// Returns a value masked with the current window state flags
uint32_t Window::GetWindowFlags()
{
    return SDL_GetWindowFlags(window.get());
}

Window::~Window()
{
}
