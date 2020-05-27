// File: Log.cc
// Author: dgrubb
// Date: 24/05/2020

// Implementation header
#include "VKEngine.h"

// C++ Library includes
#include <atomic>   // atomic
#include <iostream> // cout, endl

// C-style library includes
#include <cstdlib>  // EXIT_n macros

// Project includes
#include "Input.h"
#include "Queue.h"
#include "Video.h"
#include "Window.h"

void MainLoop(std::unique_ptr<Window> win);

int main()
{
    if (!Log::Init(VK::defaultLogLevel))
    {
        std::cout << "Couldn't start logger" << std::endl;
        return EXIT_FAILURE;
    }

    if (!Video::Init())
    {
        CRITICAL("Could not open video interface");
        return EXIT_FAILURE;
    }


    std::unique_ptr<Window> win;
    try
    {
        win.reset(
            new Window(
                std::string{VK::name},
                VK::defaultWindowWidth,
                VK::defaultWindowHeight
            )
        );
        win->Clear();
    }
    catch (const std::exception& e)
    {
        CRITICAL("Could not initialise a window: ", e.what());
        return EXIT_FAILURE;
    }

    INFO(VK::name," v", VK::version ," ready");

    MainLoop(std::move(win)); // Blocking

    Video::Deinit();

    return EXIT_SUCCESS;
}

void MainLoop(std::unique_ptr<Window> win)
{
    Queue<Input::Event> inputQ;
    std::atomic<bool> quit = false;

    while (!quit)
    {
        // Process inputs
        Input::PollInputs(inputQ);
        while (!inputQ.Empty())
        {
            auto in = inputQ.Dequeue();
            if (in == Input::Event::EXIT_REQUEST)
            {
                INFO("Exit requested");
                quit = true;
            }
        }
    }
}
