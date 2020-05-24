// File: Log.cc
// Author: dgrubb
// Date: 24/05/2020
//
// Implements logging functionality through the spdlog library (MIT-licensed).
// That library's functionality is wrappered here in case I decide to change
// the logging library at a later date and I'll only have to update a single 
// set of files.

// Implementation includes
#include "Log.h"

// C++ library includes
#include <iostream> // cout, endl

// Project includes
#include "VKEngine.h"

namespace Log
{

static constexpr spdlog::level::level_enum LogLevelTable[] = {
    spdlog::level::trace,
    spdlog::level::debug,
    spdlog::level::info,
    spdlog::level::warn,
    spdlog::level::err,
    spdlog::level::critical
};

// Sets up logging which is particular to this project such as
// formatting and log levels
bool Init(Levels level)
{
    try
    {
        auto console = spdlog::stdout_color_mt(VK::name);
        console->set_level(LogLevelTable[static_cast<int>(level)]);
        spdlog::set_default_logger(console);
    }
    catch (const spdlog::spdlog_ex& e)
    {
        std::cout << "Logger init failed: " << e.what() << std::endl;
        return false;
    }

    return true;
}

}
