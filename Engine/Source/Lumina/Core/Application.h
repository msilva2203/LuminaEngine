// This code is part of the Lumina Engine and is licensed under MIT License

#ifndef CORE_APPLICATION_H
#define CORE_APPLICATION_H

#pragma once

#include "Core/Core.h"
#include "Core/LayerStack.h"

namespace Lumina {

    class LUMINA_API Application
    {
    public:
        Application();
        virtual ~Application();

        void OnInit();
        void Run();

        void PushLayer(Layer* InLayer);
        void PopLayer(Layer* InLayer);
    
    protected:
    
    private:
        bool bRunning;
        float32 LastFrameTime;
        LayerStack MainLayerStack;
    
    };

    // To be defined in the Sandbox application
    Application* CreateApplication();
}

#endif /* CORE_APPLICATION_H */
