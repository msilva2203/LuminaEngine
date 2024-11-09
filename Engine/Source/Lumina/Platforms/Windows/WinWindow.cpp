#include "WinWindow.h"

#include "Core/Log.h"

#ifdef LUMINA_PLATFORM_WINDOWS

namespace Lumina {

    // GLFW initialized flag
    static bool bInitialized = false;

    Window* Window::Create(const FWindowSettings& WindowSettings)
    {
        return new WinWindow(WindowSettings);
    }

    WinWindow::WinWindow(const FWindowSettings& WindowSettings)
    {
        WindowData.Title = WindowSettings.Title;
        WindowData.Width = WindowSettings.Width;
        WindowData.Height = WindowSettings.Height;
        WindowData.bVSyncEnabled = WindowSettings.bVSyncEnabled;

        Init();
    }

    WinWindow::~WinWindow()
    {
        Shutdown();
    }

    void WinWindow::Init()
    {
        LUMINA_CORE_INFO("Initializing window...");

        // Run GLFW initialization code only for the first time
        if (!bInitialized) {
            // TODO: Initialize GLFW here
            bInitialized = true;
        }

        LUMINA_CORE_INFO("Window initialized");
    }

    void WinWindow::Shutdown()
    {

    }

    void WinWindow::OnUpdate()
    {

    }

    void WinWindow::SetVSync(const bool bNewValue)
    {
        // TODO: GLFW code to switch vsync here

        WindowData.bVSyncEnabled = bNewValue;
    }

}

#endif /* LUMINA_PLATFORM_WINDOWS */