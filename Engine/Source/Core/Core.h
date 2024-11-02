#ifndef CORE_H
#define CORE_H

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
    #define LUMINA_API // Defined so that errors dont appear in other files
    #error Unavailable platform
#endif

#endif

#endif /* CORE_H */
