// This code is part of the Lumina Engine and is licensed under MIT License

#include "Core/Core.h"

#include "Core/Log.h"
#include "Utility/Time.h"
#include "Core/Profiler.h"

namespace Lumina {

    static bool bInitialized = false;

    void Core::Init()
    {
        LUMINA_CORE_ASSERT(!bInitialized, "Core has already been initialized");
        
        // Initialization of every core system
        Lumina::Log::Init();
        Lumina::Time::Init();
        Lumina::Profiler::Init();

        bInitialized = true;
    }

}