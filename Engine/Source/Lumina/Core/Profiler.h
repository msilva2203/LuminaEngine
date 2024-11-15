#ifndef CORE_PROFILER_H
#define CORE_PROFILER_H

#pragma once

#include "Core/Core.h"

namespace Lumina {

    class LUMINA_API Profiler
    {
    public:
        static void Init();

    private:
        Profiler();
    };

}

#endif /* CORE_PROFILER_H */