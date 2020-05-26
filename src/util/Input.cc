// File: Input.cc
// Author: dgrubb
// Date: 26/05/2020
//
// Process event input

// Implementation header
#include "Input.h"

// Third-party includes
#include <SDL2/SDL.h>

// Project includes
#include "util/Log.h"

namespace Input
{

    void PollInputs(Queue<Event>& eq)
    {
        SDL_Event e;
        while (SDL_PollEvent(&e))
        {
            Event ev;
            if (SDL_QUIT == e.type)
            {
                ev = Event::EXIT_REQUEST;
                eq.Enqueue(ev);
                // There's no point fetching any more events, bail out
                return;
            }
        }
    }
}
