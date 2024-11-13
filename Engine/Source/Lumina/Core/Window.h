#ifndef CORE_WINDOW_H
#define CORE_WINDOW_H

#pragma once

#include "Core/Core.h"
#include "Events/Event.h"

#include <string>

namespace Lumina {

    struct FWindowSettings
    {
        std::string Title;
        int32 Width, Height;
        bool bVSyncEnabled;

        FWindowSettings() :
            Title("Lumina Window"),
            Width(1280),
            Height(720),
            bVSyncEnabled(false)
        {}

        FWindowSettings(const std::string& Title) :
            Title(Title),
            Width(1280),
            Height(720),
            bVSyncEnabled(false)
        {}

        FWindowSettings(const std::string& Title, int32 Width, int32 Height) :
            Title(Title),
            Width(Width),
            Height(Height),
            bVSyncEnabled(false)
        {}

    };

    class LUMINA_API Window
    {
    public:
        using EventCallback = std::function<void(Event&)>;

        Window() {}
        virtual ~Window() {}

        virtual void OnUpdate() = 0;

        virtual inline int32 GetWidth() const = 0;
        virtual inline int32 GetHeight() const = 0;

        virtual void SetEventCallback(const EventCallback& Callback) = 0;
        virtual void SetVSync(const bool bNewValue) = 0;
        virtual bool IsVSyncEnabled() const = 0;

        // To be defined in platform specific window class
        static Window* Create(const FWindowSettings& WindowSettings = FWindowSettings());

    protected:

    private:

    };

}

#endif /* CORE_WINDOW_H */