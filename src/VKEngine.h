// File: VKEngine.h
// Author: dgrubb
// Date: 24/05/2020
//
// Top-level header for application-wide definitions and defaults

#ifndef VKENGINE_H
#define VKENGINE_H

#include <memory> // unique_ptr

// Project includes
#include "Window.h"
#include "Log.h"

namespace VK
{
    // Application defaults
    static constexpr char name[] = "VK Engine";
    static constexpr char version[] = "0.0.1";
    static constexpr Log::Levels defaultLogLevel = Log::DEBUG;
    static constexpr int defaultWindowWidth = 256;
    static constexpr int defaultWindowHeight = 240;
}

#endif // VKENGINE_H
