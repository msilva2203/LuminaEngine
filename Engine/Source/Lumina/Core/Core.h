// This code is part of the Lumina Engine and is licensed under MIT License

#ifndef CORE_H
#define CORE_H

#pragma once

#include "Types.h" // To be included in every file

/*------------------------------------------------
    Windows
-------------------------------------------------*/
#ifdef LUMINA_PLATFORM_WINDOWS
    #define VALID_PLATFORM

    // LUMINA API definition
    #ifdef LUMINA_BUILD_DLL
        #ifdef LUMINA_CORE
            #define LUMINA_API __declspec(dllexport)
        #else
            #define LUMINA_API __declspec(dllimport)
        #endif
    #else
        #define LUMINA_API
    #endif

    // Defines DEBUGBREAK for later assertion macros
    #define DEBUGBREAK __debugbreak()
#endif

/*------------------------------------------------
    Linux
-------------------------------------------------*/
#ifdef LUMINA_PLATFORM_LINUX
    #define VALID_PLATFORM

    // LUMINA API definition
    #ifdef LUMINA_BUILD_DLL
        #ifdef LUMINA_CORE
            #define LUMINA_API
        #else
            #define LUMINA_API
        #endif
    #else
        #define LUMINA_API
    #endif

    // Defines DEBUGBREAK for later assertion macros
    //#include <signal>
    //#define DEBUGBREAK() raise(SIGTRAP)
#endif

// Unsupported platform
#ifndef VALID_PLATFORM
    #define LUMINA_API // Defined so that errors dont appear in other files
    #error Unavailable platforms
#endif

// Lumina assertion
#ifndef LUMINA_DISTRIBUTION
    // Define DEBUGBREAK if not already defined
    #ifndef DEBUGBREAK
        #define DEBUGBREAK
    #endif

    // Define assertion macros
    #define LUMINA_CORE_ASSERT(x, ...) {if (!(x)) {LUMINA_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); DEBUGBREAK;}}
    #define LUMINA_ASSERT(x, ...)      {if (!(x)) {LUMINA_ERROR("Assertion Failed: {0}", __VA_ARGS__); DEBUGBREAK;}}
#else
    // Strip assertion from distribution builds
    #define LUMINA_CORE_ASSERT(x, ...)
    #define LUMINA_ASSERT(x, ...)
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
