// File: Log.cc
// Author: dgrubb
// Date: 24/05/2020
//
// Implements logging functionality.

// Implementation include
#include "Log.h"

// Project includes
#include "VKEngine.h"

namespace Log
{

Levels current = VK::defaultLogLevel;

bool Init(Levels level)
{
    SetCurrentLevel(level);
    return true;
}

Levels GetCurrentLevel()
{
    return current;
}

void SetCurrentLevel(Levels level)
{
    current = level;
}

}
