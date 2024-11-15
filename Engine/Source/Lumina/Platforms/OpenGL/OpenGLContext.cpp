#include "OpenGLContext.h"

#include "Core/Log.h"

#include "glad/glad.h"
#include "glfw/glfw3.h"

namespace Lumina {

    OpenGLContext::OpenGLContext(GLFWwindow* WindowHandle) :
        Handle(WindowHandle)
    {
    }

    void OpenGLContext::Init()
    {
        glfwMakeContextCurrent(Handle);
        int32 GladStatus = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        LUMINA_ASSERT(GladStatus, "Failed to initialize glad");

        LUMINA_CORE_INFO("OpenGL context created");
        LUMINA_CORE_TRACE("    Vendor: {0}", (const char*)glGetString(GL_VENDOR));
        LUMINA_CORE_TRACE("    Renderer: {0}", (const char*)glGetString(GL_RENDERER));
        LUMINA_CORE_TRACE("    Version: {0}", (const char*)glGetString(GL_VERSION));
    }

    void OpenGLContext::SwapBuffers()
    {
        glfwSwapBuffers(Handle);
    }

}