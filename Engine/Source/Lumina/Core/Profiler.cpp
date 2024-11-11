#include "Core/Profiler.h"

#include "Core/Log.h"

namespace Lumina {

    static bool bInitialized = false;

    void Profiler::Init()
    {
        LUMINA_CORE_ASSERT(!bInitialized, "Profiler has already been initialized");
        bInitialized = true;
    }

}