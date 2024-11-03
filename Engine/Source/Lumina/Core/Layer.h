#ifndef CORE_LAYER_H
#define CORE_LAYER_H

#include "Core.h"

#include <string>

namespace Lumina {

    class LUMINA_API Layer
    {
    public:
        Layer(const std::string& Name = "MyLayer");
        ~Layer();

        virtual void OnBind() {}
        virtual void OnUnbind() {}
        virtual void OnUpdate(float DeltaTime) {}
        virtual void OnRender() {}

    protected:

    private:
        std::string DebugName;

    };

}

#endif /* CORE_LAYER_H */