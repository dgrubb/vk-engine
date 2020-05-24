// File: Log.cc
// Author: dgrubb
// Date: 24/05/2020

// Implementation header
#include "VKEngine.h"

// C-style library includes
#include <cstdlib> // EXIT_n macros

// Project includes
#include "util/Log.h"

int main()
{
    if (!Log::Init(Log::DEBUG))
    {
        return EXIT_FAILURE;
    }

    INFO("{} ready", VK::name);

    return EXIT_SUCCESS;
}
