// This code is part of the Lumina Engine and is licensed under MIT License

#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace Lumina {

    static bool bInitialized = false;
    
    std::shared_ptr<spdlog::logger> Log::CoreLogger;
    std::shared_ptr<spdlog::logger> Log::ClientLogger;

    void Log::Init()
    {
        spdlog::set_pattern("%^[%T] %n: %v%$");

        CoreLogger = spdlog::stdout_color_mt("LUMINA");
        CoreLogger->set_level(spdlog::level::trace);

        ClientLogger = spdlog::stdout_color_mt("CLIENT");
        ClientLogger->set_level(spdlog::level::trace);

        LUMINA_CORE_ASSERT(!bInitialized, "Log has already been initialized");
        bInitialized = true;
    }

}
