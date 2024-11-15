// This code is part of the Lumina Engine and is licensed under MIT License

#include "LayerStack.h"

namespace Lumina {

    LayerStack::LayerStack()
    {
    }

    LayerStack::~LayerStack()
    {
        for (auto& StackElement : this->Stack)
        {
            delete StackElement;
        }
    }

    void LayerStack::PushLayer(Layer* InLayer)
    {
        if (!this->Stack.Contains(InLayer)) {
            this->Stack.Add(InLayer);
            InLayer->OnAttach();
        }
    }

    void LayerStack::PopLayer(Layer* InLayer)
    {
        this->Stack.Remove(InLayer);
        InLayer->OnDettach();
    }

}