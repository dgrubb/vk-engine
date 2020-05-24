// File: Video.cc
// Author: dgrubb
// Date: 24/05/2020
//
// Low-level interfacing with display output

// Implementation header
#include "Video.h"

// Third-party includes
#include <SDL2/SDL.h>

// Project includes
#include "util/Log.h"

namespace Video
{

bool Init()
{
    DEBUG("Starting SDL");
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO))
    {
        ERROR("Failed to open SDL: {}", SDL_GetError());
        return false;
    }
    return true;
}

void Deinit()
{
    DEBUG("Closing SDL");
    SDL_Quit();
}

}
