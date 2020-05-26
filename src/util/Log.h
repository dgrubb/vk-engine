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

// C++ standard includes
#include <iostream> // cout
#include <sstream>  // ostringstream

#define TRACE(...) if (Log::Levels::TRACE >= Log::GetCurrentLevel()) \
    Log::Log("TRACE", __LINE__, __FILE__, __FUNCTION__, __VA_ARGS__)

#define DEBUG(...) if (Log::Levels::DEBUG >= Log::GetCurrentLevel()) \
    Log::Log("DEBUG", __LINE__, __FILE__, __FUNCTION__, __VA_ARGS__)

#define INFO(...) if (Log::Levels::INFO >= Log::GetCurrentLevel()) \
    Log::Log("INFO", __LINE__, __FILE__, __FUNCTION__, __VA_ARGS__)

#define WARN(...) if (Log::Levels::WARN >= Log::GetCurrentLevel()) \
    Log::Log("WARN", __LINE__, __FILE__, __FUNCTION__, __VA_ARGS__)

#define ERROR(...) if (Log::Levels::ERROR >= Log::GetCurrentLevel()) \
    Log::Log("ERROR", __LINE__, __FILE__, __FUNCTION__, __VA_ARGS__)

#define CRITICAL(...) if (Log::Levels::CRITICAL >= Log::GetCurrentLevel()) \
    Log::Log("CRITICAL", __LINE__, __FILE__, __FUNCTION__, __VA_ARGS__)

namespace Log {

enum Levels {
    TRACE = 0,
    DEBUG,
    INFO,
    WARN,
    ERROR,
    CRITICAL
};

template <typename ...Args>
void Log(const char* level, int line, const char* file, const char* function, Args&& ...args)
{
    std::ostringstream ss;
    ss << "[" << level << "] " << file << ":" << line << " ( " << function << " ) ";
    (ss << ... << std::forward<Args>(args)) << "\n";

    std::cout << ss.str().c_str();
}

bool Init(Levels level);
Levels GetCurrentLevel();
void SetCurrentLevel(Levels level);

}

#endif // LOG_H
