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
  :
    // Request a window context from the windowing provider
    window(
        SDL_CreateWindow(
            name.c_str(),
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            width, height,
            SDL_WINDOW_OPENGL
        ),
        SDL_DestroyWindow
    ),
    // Create an interface for executing render requests against the
    // new window context
    renderer(
        SDL_CreateRenderer(
            window.get(), -1,
            (SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)
        ),
        SDL_DestroyRenderer)
{
    // Sanity checks
    if (nullptr == window)
    {
        throw std::runtime_error("Failed to create window context");
    }
    if (nullptr == renderer)
    {
        throw std::runtime_error("Failed to initialise a renderer");
    }
    int w, h;
    SDL_GetWindowSize(window.get(), &w, &h);
    INFO("Created window [{}]: {}x{}", SDL_GetWindowTitle(window.get()), w, h);
}

void Window::Clear()
{
    SDL_SetRenderDrawColor(renderer.get(), 255, 255, 255, 255);
    SDL_RenderClear(renderer.get());
    Render();
}

// N.b., fullscreen in this context means truly fullscreen, not whether the
// window has been scaled to overlay the whole window as determined by
// SDL_WINDOW_FULLSCREEN_DESKTOP
bool Window::GetFullscreen()
{
    return (GetWindowFlags() & SDL_WINDOW_FULLSCREEN);
}

// Most of the transformations applied through the renderer are applied to an
// internal buffer and don't get processed by the display until this method is
// called. In this way operations can be optimised by applying them in
// succession and procesing them as a batch
void Window::Render()
{
    SDL_RenderPresent(renderer.get());
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
    renderer.reset();
    window.reset();
}
