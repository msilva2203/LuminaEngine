// This code is part of the Lumina Engine and is licensed under MIT License

#ifndef CORE_LAYERSTACK_H
#define CORE_LAYERSTACK_H

#pragma once

#include "Core/Core.h"
#include "Core/Layer.h"
#include "Core/Array.h"

namespace Lumina {

    class LUMINA_API LayerStack
    {
    public:
        using Iterator = TArray<Layer*>::Iterator;
        using ConstIterator = TArray<Layer*>::ConstIterator;

        LayerStack();
        ~LayerStack();

        void PushLayer(Layer* InLayer);
        void PopLayer(Layer* InLayer);

        Iterator begin() { return Stack.begin(); }
        Iterator end() { return Stack.end(); }
        ConstIterator begin() const { return Stack.begin(); }
        ConstIterator end() const { return Stack.end(); }

    protected:

    private:
        TArray<Layer*> Stack;

    };

}

#endif /* CORE_LAYERSTACK_H */