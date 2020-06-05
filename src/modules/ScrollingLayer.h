// File: ScrollingLayer.h
// Author: dgrubb
// Date: 30/05/2020
//
// Provides a scrollable image layer.

#ifndef SCROLLINGLAYER_H
#define SCROLLINGLAYER_H

// C++ Library headers
#include <string>      // string
#include <string_view> // string_view

// C-style library includes
#include <cstdint>     // uint32_t

// Third-party includes
#include <SDL2/SDL.h>

class ScrollingLayer
{
    public:

        ScrollingLayer(std::string_view id_, uint32_t width_, uint32_t height_);
        ~ScrollingLayer();

        ScrollingLayer(const ScrollingLayer&) = delete;
        ScrollingLayer(ScrollingLayer&&) = delete;
        ScrollingLayer& operator=(const ScrollingLayer&) = delete;
        ScrollingLayer& operator=(ScrollingLayer&) = delete;

    private:

        std::string id{""};
        uint32_t width{0};
        uint32_t height{0};
        uint32_t veriticalOffset{0};
        uint32_t horizontalOffet{0};

};

#endif // SCROLLINGLAYER_H
