// File: Log.cc
// Author: dgrubb
// Date: 24/05/2020

// Implementation header
#include "VKEngine.h"

// C-style library includes
#include <cstdlib> // EXIT_n macros

// Project includes
#include "components/Window.h"
#include "util/Video.h"

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

    auto win = std::make_unique<Window>(std::string{VK::name}, 800, 600);

    INFO("{} v{} ready", VK::name, VK::version);

    Video::Deinit();

    return EXIT_SUCCESS;
}
