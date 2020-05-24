// File: Log.cc
// Author: dgrubb
// Date: 24/05/2020

// Implementation header
#include "VKEngine.h"

// C-style library includes
#include <cstdlib> // EXIT_n macros

int main()
{
    if (!Log::Init(VK::defaultLogLevel))
    {
        return EXIT_FAILURE;
    }

    INFO("{} v{} ready", VK::name, VK::version);

    return EXIT_SUCCESS;
}
