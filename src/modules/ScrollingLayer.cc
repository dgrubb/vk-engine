// File: ScrollingLayer.cc
// Author: dgrubb
// Date: 30/05/2020
//
// Provides a scrollable image layer.

// Implementation include
#include "ScrollingLayer.h"

// C++ Library headers

// Third-party includes
#include <SDL2/SDL.h>

// Project includes
#include "util/Log.h"

ScrollingLayer::ScrollingLayer(std::string_view id_, uint32_t width_, uint32_t height_)
  :
    id(id_),
    width(width_),
    height(height_)
{
    INFO("Created scrollable layer: ", id);
}

ScrollingLayer::~ScrollingLayer()
{
}
