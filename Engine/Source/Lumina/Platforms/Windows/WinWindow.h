#ifndef PLATFORMS_WINWINDOW_H
#define PLATFORMS_WINWINDOW_H

#pragma once

#include "Core/Core.h"
#include "Core/Window.h"

//#define LUMINA_PLATFORM_WINDOWS
#ifdef LUMINA_PLATFORM_WINDOWS

#include "GLFW/glfw3.h"

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
        GLFWwindow* WindowPtr;

    };

}

#endif /* LUMINA_PLATFORM_WINDOWS */

#endif /* PLATFORM_WINWINDOW_H */