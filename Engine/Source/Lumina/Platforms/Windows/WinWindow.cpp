#include "WinWindow.h"

#include "Core/Log.h"

#ifdef LUMINA_PLATFORM_WINDOWS

namespace Lumina {

    // GLFW window instances
    static int32 WindowInstances = 0;

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
        if (WindowInstances <= 0) {
            int32 Success = glfwInit();
            LUMINA_CORE_ASSERT(Success == GLFW_TRUE, "GLFW failed to initialize");
            WindowInstances = 1;
        } else {
            WindowInstances++;
        }

        // Creation of the actual window
        WindowPtr = glfwCreateWindow(WindowData.Width, WindowData.Height, WindowData.Title.c_str(), NULL, NULL);
        LUMINA_CORE_ASSERT(WindowPtr != nullptr, "Failed to create window");

        glfwMakeContextCurrent(WindowPtr);
        glfwSetWindowUserPointer(WindowPtr, &WindowData);

        LUMINA_CORE_INFO("Window initialized");
    }

    void WinWindow::Shutdown()
    {
        glfwDestroyWindow(WindowPtr);
        WindowInstances--;

        if (WindowInstances <= 0) {
            glfwTerminate();
            WindowInstances = 0;
        }
    }

    void WinWindow::OnUpdate()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glfwSwapBuffers(WindowPtr);
        glfwPollEvents();
    }

    void WinWindow::SetVSync(const bool bNewValue)
    {
        if (bNewValue) {
            glfwSwapInterval(1);
        } else {
            glfwSwapInterval(0);
        }
        WindowData.bVSyncEnabled = bNewValue;
    }
}

#endif /* LUMINA_PLATFORM_WINDOWS */