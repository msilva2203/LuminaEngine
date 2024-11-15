#ifndef RENDERER_RENDERING_CONTEXT_H
#define RENDERER_RENDERING_CONTEXT_H

#include "Core/Core.h"

namespace Lumina {

    class LUMINA_API RenderingContext
    {
    public:
        virtual void Init() = 0;
        virtual void SwapBuffers() = 0;
    };

}

#endif /* LUMINA_RENDERING_CONTEXT_H */