// This code is part of the Lumina Engine and is licensed under MIT License

#include "Time.h"

#include "Core/Core.h"
#include "Core/Log.h"

#include <thread>
#include <chrono>

namespace Lumina {

    Time::Time() :
        StartTimePoint(std::chrono::steady_clock::now())
    {}

    float32 Time::GetElapsedSeconds()
    {
        auto Now = std::chrono::steady_clock::now();
        std::chrono::duration<float32> ElapsedTime = Now - this->StartTimePoint;
        return ElapsedTime.count();
    }

    void Time::Sleep(float32 Duration)
    {
        std::this_thread::sleep_for(std::chrono::duration<float32>(Duration));
    }

}