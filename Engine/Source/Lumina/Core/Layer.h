// This code is part of the Lumina Engine and is licensed under MIT License

#ifndef CORE_LAYER_H
#define CORE_LAYER_H

#pragma once

#include "Core/Core.h"
#include "Core/Object.h"

#include <string>

namespace Lumina {

    class LUMINA_API Layer : public Object
    {
    public:
        Layer(const std::string& DebugName = "MyLayer");
        virtual ~Layer();

        virtual void OnAttach() {}
        virtual void OnDettach() {}
        virtual void OnUpdate(float32 DeltaTime) {}

    protected:

    private:

    };

}

#endif /* CORE_LAYER_H */