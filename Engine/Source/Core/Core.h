#ifndef CORE_H
#define CORE_H

// The following definitions should be defined in build stage
#define LUMINA_CORE // Temporary
#define LUMINA_PLATFORM_LINUX // Temporary

// LUMINA_API definition
#ifdef LUMINA_PLATFORM_WINDOWS
    #ifdef LUMINA_CORE
        #define LUMINA_API __declspec(dllexport)
    #else
        #define LUMINA_API __declspec(dllimport)
    #endif
#else
#ifdef LUMINA_PLATFORM_LINUX
    #ifdef LUMINA_CORE
        #define LUMINA_API __declspec(dllexport)
    #else
        #define LUMINA_API __declspec(dllimport)
    #endif
#else
    #error Unavailable platform
#endif
#endif

#endif /* CORE_H */
