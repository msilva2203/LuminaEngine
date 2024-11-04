#ifndef PLATFORMS_WINWINDOW_H
#define PLATFORMS_WINWINDOW_H

#pragma once

#ifdef LUMINA_PLATFORM_WINDOWS

#include "Core/Core.h"
#include "Core/Window.h"

namespace Lumina {

    struct FWindowData
    {
        std::string Title;
        int32 Width, Height;
        bool bVSyncEnabled;
    };

    class LUMINA_API WinWindow : public Window
    {
    public:
        WinWindow(const FWindowSettings& WindowSettings);
        ~WinWindow();

        void Init();
        void Shutdown();
        virtual void OnUpdate() override;

        virtual inline int32 GetWidth() const override { return WindowData.Width; }
        virtual inline int32 GetHeight() const override { return WindowData.Height; }

        virtual void SetVSync(const bool bNewValue) override;
        virtual bool IsVSyncEnabled() const override { return WindowData.bVSyncEnabled; }

    private:
        FWindowData WindowData;

    };

}

#endif /* LUMINA_PLATFORM_WINDOWS */

#endif /* PLATFORM_WINWINDOW_H */