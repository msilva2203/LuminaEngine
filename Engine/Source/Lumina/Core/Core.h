// This code is part of the Lumina Engine and is licensed under MIT License

#ifndef CORE_H
#define CORE_H

#pragma once

#include "Types.h" // To be included in every core file

// Windows LUMINA_API definition
#ifdef LUMINA_PLATFORM_WINDOWS
    #ifdef LUMINA_CORE
        #define LUMINA_API __declspec(dllexport)
    #else
        #define LUMINA_API __declspec(dllimport)
    #endif
#else

// Linux LUMINA_API definition
#ifdef LUMINA_PLATFORM_LINUX
    #ifdef LUMINA_CORE
        #define LUMINA_API
    #else
        #define LUMINA_API
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
