#ifndef CORE_LAYERSTACK_H
#define CORE_LAYERSTACK_H

#include "Core.h"
#include "Core/Layer.h"
#include "Core/Array.h"

namespace Lumina {

    class LUMINA_API LayerStack
    {
    public:
        LayerStack();
        ~LayerStack();

        void OnUpdate(float DeltaTime);
        void OnRender();

        void PushLayer(Layer* InLayer);
        void PopLayer(Layer* InLayer);

    protected:

    private:
        TArray<Layer*> Stack;

    };

}

#endif /* CORE_LAYERSTACK_H */