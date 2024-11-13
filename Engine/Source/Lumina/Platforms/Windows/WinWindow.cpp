#include "WinWindow.h"

#include "Core/Log.h"
#include "Events/ApplicationEvents.h"
#include "Events/KeyEvents.h"
#include "Events/MouseEvents.h"

#ifdef LUMINA_PLATFORM_WINDOWS

namespace Lumina {

    // GLFW window instances
    static int32 WindowInstances = 0;

    /**
     * Serves as the callback function for glfw errors
     */
    static void ErrorCallback(int Error, const char* Description)
    {
        LUMINA_CORE_ERROR("GLFW error ({0}): {1}", Error, Description);
    }

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

        // Run GLFW initialization code only if needed
        if (WindowInstances <= 0) {
            int32 Success = glfwInit();
            LUMINA_CORE_ASSERT(Success == GLFW_TRUE, "GLFW failed to initialize");
            glfwSetErrorCallback(ErrorCallback);
            WindowInstances = 1;
        } else {
            WindowInstances++;
        }

        // Creation of the actual window
        WindowHandle = glfwCreateWindow(WindowData.Width, WindowData.Height, WindowData.Title.c_str(), NULL, NULL);
        LUMINA_CORE_ASSERT(WindowHandle != nullptr, "Failed to create window");

        glfwMakeContextCurrent(WindowHandle);
        glfwSetWindowUserPointer(WindowHandle, &WindowData);

        // Bind GLFW window callbacks
        glfwSetWindowCloseCallback(WindowHandle, [](GLFWwindow* window)
        {
            FWindowData& WindowUserData = *(FWindowData*)glfwGetWindowUserPointer(window);

            WindowCloseEvent Event;
            WindowUserData.Callback(Event);
        });

        glfwSetWindowSizeCallback(WindowHandle, [](GLFWwindow* window, int width, int height)
        {
            FWindowData& WindowUserData = *(FWindowData*)glfwGetWindowUserPointer(window);

            WindowUserData.Width = width;
            WindowUserData.Height = height;
            
            WindowResizeEvent Event(width, height);
            WindowUserData.Callback(Event);
        });

        glfwSetKeyCallback(WindowHandle, [](GLFWwindow* window, int key, int scancode, int action, int mods)
        {
            FWindowData& WindowUserData = *(FWindowData*)glfwGetWindowUserPointer(window);

            switch (action)
            {
                case GLFW_PRESS:
                {
                    KeyPressedEvent Event(key, false);
                    WindowUserData.Callback(Event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    KeyReleasedEvent Event(key);
                    WindowUserData.Callback(Event);
                    break;
                }
                case GLFW_REPEAT:
                {
                    KeyPressedEvent Event(key, true);
                    WindowUserData.Callback(Event);
                    break;
                }
            }

        });

        glfwSetMouseButtonCallback(WindowHandle, [](GLFWwindow* window, int button, int action, int mods)
        {
            FWindowData& WindowUserData = *(FWindowData*)glfwGetWindowUserPointer(window);

            switch (action) {
                case GLFW_PRESS:
                {
                    MouseButtonPressedEvent Event(button);
                    WindowUserData.Callback(Event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    MouseButtonReleasedEvent Event(button);
                    WindowUserData.Callback(Event);
                    break;
                }
            }

        });

        glfwSetScrollCallback(WindowHandle, [](GLFWwindow* window, double xoffset, double yoffset)
        {
            FWindowData& WindowUserData = *(FWindowData*)glfwGetWindowUserPointer(window);

            MouseScrolledEvent Event((float32)xoffset, (float32)yoffset);
            WindowUserData.Callback(Event);
        });

        glfwSetCursorPosCallback(WindowHandle, [](GLFWwindow* window, double xpos, double ypos)
        {
            FWindowData& WindowUserData = *(FWindowData*)glfwGetWindowUserPointer(window);

            MouseMovedEvent Event((float32)xpos, (float32)ypos);
            WindowUserData.Callback(Event);
        });

        LUMINA_CORE_INFO("Window initialized");
    }

    void WinWindow::Shutdown()
    {
        glfwDestroyWindow(WindowHandle);
        WindowInstances--;

        if (WindowInstances <= 0) {
            glfwTerminate();
            WindowInstances = 0;
        }
    }

    void WinWindow::OnUpdate()
    {
        glfwSwapBuffers(WindowHandle);
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