// File: Log.h
// Author: dgrubb
// Date: 24/05/2020
//
// Implements logging functionality through the spdlog library (MIT-licensed).
// That library's functionality is wrappered here in case I decide to change
// the logging library at a later date and I'll only have to update a single 
// set of files.

#ifndef LOG_H
#define LOG_H

// Third-party libraries
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

// Wrapper library specific macros with generic ones
#define TRACE(...) \
    SPDLOG_TRACE(__VA_ARGS__);

#define DEBUG(...) \
    SPDLOG_DEBUG(__VA_ARGS__);

#define INFO(...) \
    SPDLOG_INFO(__VA_ARGS__);

#define WARN(...) \
    SPDLOG_WARNING(__VA_ARGS__);

#define ERROR(...) \
    SPDLOG_ERROR(__VA_ARGS__);

#define CRITICAL(...) \
    SPDLOG_CRITICAL(__VA_ARGS__);

namespace Log {

enum Levels {
    TRACE = 0,
    DEBUG,
    INFO,
    WARN,
    ERROR,
    CRITICAL
};

bool Init(Levels level);

}

#endif // LOG_H
