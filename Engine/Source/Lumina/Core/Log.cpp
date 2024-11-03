#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace Lumina {
    
    std::shared_ptr<spdlog::logger> Log::CoreLogger;
    std::shared_ptr<spdlog::logger> Log::ClientLogger;

    void Log::Init()
    {
        spdlog::set_pattern("%^[%T] %n: %v%$");

        CoreLogger = spdlog::stdout_color_mt("LUMINA");
        CoreLogger->set_level(spdlog::level::trace);

        ClientLogger = spdlog::stdout_color_mt("CLIENT");
        ClientLogger->set_level(spdlog::level::trace);
    }

    std::shared_ptr<spdlog::logger>& Log::GetCoreLogger()
    {
        return CoreLogger;
    }

    std::shared_ptr<spdlog::logger>& Log::GetClientLogger()
    {
        return ClientLogger;
    }

}
