// This code is part of the Lumina Engine and is licensed under MIT License

#ifndef CORE_TIME_H
#define CORE_TIME_H

#pragma once

#include "Core/Core.h"

#include <chrono>

namespace Lumina {

    /**
     * Allows the user to access time related properties
     */
    class LUMINA_API Time
    {
    public:
        Time();
        ~Time() {}

        float32 GetElapsedSeconds();
        static void Sleep(float32 Duration);

    protected:

    private:
        std::chrono::steady_clock::time_point StartTimePoint;

    };

}

#endif /* CORE_TIME_H */