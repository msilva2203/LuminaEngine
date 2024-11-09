#ifndef PLATFORMS_LINUXWINDOW_H
#define PLATFORMS_LINUXWINDOW_H

#pragma once

#include "Core/Core.h"
#include "Core/Window.h"

#ifdef LUMINA_PLATFORM_LINUX

#include "GLFW/glfw3.h"

namespace Lumina {

    struct FWindowData
    {
        std::string Title;
        int32 Width, Height;
        bool bVSyncEnabled;
    };

    class LUMINA_API LinuxWindow : public Window
    {
    public:
        LinuxWindow(const FWindowSettings& WindowSettings);
        ~LinuxWindow();

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

#endif /* LUMINA_PLATFORM_LINUX */

#endif /* PLATFORMS_LINUXWINDOW_H */