// This code is part of the Lumina Engine and is licensed under MIT License

#include "Time.h"

#include "Core/Log.h

#include <thread>
#include <chrono>

namespace Lumina {

    static bool bInitialized = false;

    std::chrono::steady_clock::time_point Time::StartTimePoint;

    void Time::Init()
    {
        LUMINA_CORE_ASSERT(!bInitialized, "Time has already been initialized");
        
        StartTimePoint = std::chrono::steady_clock::now();

        bInitialized = true;
    }

    float32 Time::GetElapsedSeconds()
    {
        auto Now = std::chrono::steady_clock::now();
        std::chrono::duration<float32> ElapsedTime = Now - StartTimePoint;
        return ElapsedTime.count();
    }

    void Time::Sleep(float32 Duration)
    {
        std::this_thread::sleep_for(std::chrono::duration<float32>(Duration));
    }

}