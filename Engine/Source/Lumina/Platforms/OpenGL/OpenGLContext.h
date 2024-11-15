#ifndef PLATFORMS_OPENGL_CONTEXT
#define PLATFORMS_OPENGL_CONTEXT

#include "Renderer/RenderingContext.h"

struct GLFWwindow;

namespace Lumina {

    class LUMINA_API OpenGLContext : public RenderingContext
    {
    public:
        OpenGLContext(GLFWwindow* WindowHandle);

        virtual void Init() override;
        virtual void SwapBuffers() override;

    private:
        GLFWwindow* Handle;
    };

}

#endif /* LUMINA_OPENGL_CONTEXT */