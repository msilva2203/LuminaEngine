// This code is part of the Lumina Engine and is licensed under MIT License

#ifndef CORE_LOG_H
#define CORE_LOG_H

#include "Core.h"

#include <memory>
#include "spdlog/spdlog.h"

namespace Lumina {

    class LUMINA_API Log
    {
    public:
        Log() = delete;

        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger();
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger();

    private:
        static std::shared_ptr<spdlog::logger> CoreLogger;
        static std::shared_ptr<spdlog::logger> ClientLogger;
    };

}

#define LUMINA_LOG_FATAL(Log, ...)        Log->fatal(__VA_ARGS__)
#define LUMINA_LOG_ERROR(Log, ...)        Log->error(__VA_ARGS__)
#define LUMINA_LOG_WARN(Log, ...)         Log->warn(__VA_ARGS__)
#define LUMINA_LOG_INFO(Log, ...)         Log->info(__VA_ARGS__)
#define LUMINA_LOG_TRACE(Log, ...)        Log->trace(__VA_ARGS__)

#define LUMINA_CORE_FATAL(...)            LUMINA_LOG_FATAL(Lumina::Log::GetCoreLogger(), __VA_ARGS__)
#define LUMINA_CORE_ERROR(...)            LUMINA_LOG_ERROR(Lumina::Log::GetCoreLogger(), __VA_ARGS__)
#define LUMINA_CORE_WARN(...)             LUMINA_LOG_WARN(Lumina::Log::GetCoreLogger(), __VA_ARGS__)
#define LUMINA_CORE_INFO(...)             LUMINA_LOG_INFO(Lumina::Log::GetCoreLogger(), __VA_ARGS__)
#define LUMINA_CORE_TRACE(...)            LUMINA_LOG_TRACE(Lumina::Log::GetCoreLogger(), __VA_ARGS__)

#define LUMINA_FATAL(...)                 LUMINA_LOG_FATAL(Lumina::Log::GetClientLogger(), __VA_ARGS__)
#define LUMINA_ERROR(...)                 LUMINA_LOG_ERROR(Lumina::Log::GetClientLogger(), __VA_ARGS__)
#define LUMINA_WARN(...)                  LUMINA_LOG_WARN(Lumina::Log::GetClientLogger(), __VA_ARGS__)
#define LUMINA_INFO(...)                  LUMINA_LOG_INFO(Lumina::Log::GetClientLogger(), __VA_ARGS__)
#define LUMINA_TRACE(...)                 LUMINA_LOG_TRACE(Lumina::Log::GetClientLogger(), __VA_ARGS__)

#ifdef LUMINA_DISTRIBUTION

    #define LUMINA_LOG_FATAL(Log, ...)
    #define LUMINA_LOG_ERROR(Log, ...)
    #define LUMINA_LOG_WARN(Log, ...)
    #define LUMINA_LOG_INFO(Log, ...)
    #define LUMINA_LOG_TRACE(Log, ...)

    #define LUMINA_CORE_FATAL(...)
    #define LUMINA_CORE_ERROR(...)
    #define LUMINA_CORE_WARN(...)
    #define LUMINA_CORE_INFO(...)
    #define LUMINA_CORE_TRACE(...)

    #define LUMINA_FATAL(...)
    #define LUMINA_ERROR(...)
    #define LUMINA_WARN(...)
    #define LUMINA_INFO(...)
    #define LUMINA_TRACE(...)

#endif /* LUMINA_DISTRIBUTION */

#endif /* CORE_LOG_H */
