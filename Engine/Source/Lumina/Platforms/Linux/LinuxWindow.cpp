#include "LinuxWindow.h"

#include "Core/Log.h"

#ifdef LUMINA_PLATFORM_LINUX

namespace Lumina {

    // GLFW window instances
    static int32 WindowInstances = 0;

    Window* Window::Create(const FWindowSettings& WindowSettings)
    {
        return new LinuxWindow(WindowSettings);
    }

    LinuxWindow::LinuxWindow(const FWindowSettings& WindowSettings)
    {
        WindowData.Title = WindowSettings.Title;
        WindowData.Width = WindowSettings.Width;
        WindowData.Height = WindowSettings.Height;
        WindowData.bVSyncEnabled = WindowSettings.bVSyncEnabled;

        Init();
    }

    LinuxWindow::~LinuxWindow()
    {
        Shutdown();
    }

    void LinuxWindow::Init()
    {
        LUMINA_CORE_INFO("Initializing window...");

        // Run GLFW initialization code only if needed
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

    void LinuxWindow::Shutdown()
    {
        glfwDestroyWindow(WindowPtr);
        WindowInstances--;

        if (WindowInstances <= 0) {
            glfwTerminate();
            WindowInstances = 0;
        }
    }

    void LinuxWindow::OnUpdate()
    {
        glfwSwapBuffers(WindowPtr);
        glfwPollEvents();
    }

    void LinuxWindow::SetVSync(const bool bNewValue)
    {
        if (bNewValue) {
            glfwSwapInterval(1);
        } else {
            glfwSwapInterval(0);
        }
        WindowData.bVSyncEnabled = bNewValue;
    }

}

#endif /* LUMINA_PLATFORM_LINUX */