#include "LayerStack.h"

namespace Lumina {

    LayerStack::LayerStack()
    {

    }

    LayerStack::~LayerStack()
    {
        for (auto& StackElement : Stack)
        {
            delete StackElement;
        }
    }

    void LayerStack::OnUpdate(float DeltaTime)
    {
        for (auto& StackElement : Stack)
        {
            StackElement->OnUpdate(DeltaTime);
        }
    }

    void LayerStack::OnRender()
    {
        for (auto& StackElement : Stack)
        {
            StackElement->OnRender();
        }
    }

    void LayerStack::PushLayer(Layer* InLayer)
    {
        if (!Stack.Contains(InLayer)) {
            Stack.Add(InLayer);
        }
    }

    void LayerStack::PopLayer(Layer* InLayer)
    {
        Stack.Remove(InLayer);
    }

}