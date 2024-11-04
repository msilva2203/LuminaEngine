// This code is part of the Lumina Engine and is licensed under MIT License

#ifndef CORE_H
#define CORE_H

#pragma once

#include "Types.h" // To be included in every file

// Windows specific defines
#ifdef LUMINA_PLATFORM_WINDOWS
    // LUMINA API definition
    #ifdef LUMINA_CORE
        #define LUMINA_API __declspec(dllexport)
    #else
        #define LUMINA_API __declspec(dllimport)
    #endif

    // Lumina assertion
    #ifndef LUMINA_DISTRIBUTION
        #define LUMINA_CORE_ASSERT(x, ...) {if (!(x)) {LUMINA_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
        #define LUMINA_ASSERT(x, ...)      {if (!(x)) {LUMINA_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
    #else
        #define LUMINA_CORE_ASSERT(x, ...)
        #define LUMINA_ASSERT(x, ...)
    #endif
#else

// Linux
#ifdef LUMINA_PLATFORM_LINUX
    // LUMINA API definition
    #ifdef LUMINA_CORE
        #define LUMINA_API
    #else
        #define LUMINA_API
    #endif

    // Lumina assertion
    #ifndef LUMINA_DISTRIBUTION
        #include <signal>
        #define LUMINA_CORE_ASSERT(x, ...) {if (!(x)) {LUMINA_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); raise(SIGTRAP)}}
        #define LUMINA_ASSERT(x, ...)      {if (!(x)) {LUMINA_ERROR("Assertion Failed: {0}", __VA_ARGS__); raise(SIGTRAP)}}
    #else
        #define LUMINA_CORE_ASSERT(x, ...)
        #define LUMINA_ASSERT(x, ...)
    #endif
#else

// Unsupported platform
#define LUMINA_API // Defined so that errors dont appear in other files
#error Unavailable platforms
#endif

#endif

namespace Lumina {

    /**
     * Allows the initialization of the Lumina Core
     */
    class LUMINA_API Core
    {
    public:
        Core() = delete;

        static void Init();
    };

}

#endif /* CORE_H */
