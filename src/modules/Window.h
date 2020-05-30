// File: Window.h
// Author: dgrubb
// Date: 24/05/2020
//
// Handles interfacing with the the window context which provides
// display output and captures incoming key/mouse input events.

#ifndef WINDOW_H
#define WINDOW_H

// C++ Library headers
#include <memory>  // unique_ptr
#include <string>  // string

// C-style library includes
#include <cstdint> // uint32_t

// Third-party includes
#include <SDL2/SDL.h>

class Window
{
    public:

        Window(std::string name, int width, int height);
        ~Window();

        Window(const Window&) = delete;
        Window(Window&&) = delete;
        Window& operator=(const Window&) = delete;
        Window& operator=(Window&) = delete;

        // Getters
        bool GetFullscreen();

        // Setters
        bool SetFullscreen(bool fullscreen);
        bool SetScale(float scale);
        bool SetScale(float scaleX, float scaleY);

        // Methods
        void Clear();
        bool Update();

    private:

        // Data
        std::unique_ptr<SDL_Window, void(*)(SDL_Window*)> window;
        std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)> renderer;

        // Methods
        uint32_t GetWindowFlags();
        void Render();
};

#endif // WINDOW_H
