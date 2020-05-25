// File: Log.cc
// Author: dgrubb
// Date: 24/05/2020

// Implementation header
#include "VKEngine.h"

// C-style library includes
#include <cstdlib> // EXIT_n macros

// Project includes
#include "Window.h"
#include "Video.h"

int main()
{
    if (!Log::Init(VK::defaultLogLevel))
    {
        return EXIT_FAILURE;
    }

    if (!Video::Init())
    {
        CRITICAL("Could not open video interface");
        return EXIT_FAILURE;
    }

    try
    {
        auto win = std::make_unique<Window>(
                std::string{VK::name},
                VK::defaultWindowWidth,
                VK::defaultWindowHeight
        );
    }
    catch (const std::exception& e)
    {
        CRITICAL("Could not initialise a window: {}", e.what());
        return EXIT_FAILURE;
    }

    INFO("{} v{} ready", VK::name, VK::version);

    Video::Deinit();

    return EXIT_SUCCESS;
}
