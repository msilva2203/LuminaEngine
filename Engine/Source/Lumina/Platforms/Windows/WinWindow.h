#ifndef PLATFORMS_WINWINDOW_H
#define PLATFORMS_WINWINDOW_H

#pragma once

#include "Core/Core.h"
#include "Core/Window.h"
#include "Renderer/RenderingContext.h"

#ifdef LUMINA_PLATFORM_WINDOWS

#include "GLFW/glfw3.h"

namespace Lumina {

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

        virtual inline void SetEventCallback(const EventCallback& Callback) override { WindowData.Callback = Callback; }
        virtual void SetVSync(const bool bNewValue) override;
        virtual bool IsVSyncEnabled() const override { return WindowData.bVSyncEnabled; }

    private:

        /**
         * Holds data specific to the platform
         */
        struct FWindowData
        {
            std::string Title;
            int32 Width, Height;
            bool bVSyncEnabled;

            Window::EventCallback Callback;
        };

        FWindowData WindowData;
        GLFWwindow* WindowHandle;
        RenderingContext* Context;

    };

}

#endif /* LUMINA_PLATFORM_WINDOWS */

#endif /* PLATFORM_WINWINDOW_H */