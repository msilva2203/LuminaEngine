// This code is part of the Lumina Engine and is licensed under MIT License

#include "Core/Core.h"

#include "Core/Log.h"
#include "Core/Time.h"

namespace Lumina {

    void Core::Init()
    {
        // Initialization of every core system
        Lumina::Log::Init();
        Lumina::Time::Init();
    }

}