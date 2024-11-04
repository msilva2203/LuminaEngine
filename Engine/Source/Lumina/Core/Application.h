// This code is part of the Lumina Engine and is licensed under MIT License

#ifndef CORE_APPLICATION_H
#define CORE_APPLICATION_H

#pragma once

#include "Core/Core.h"
#include "Core/LayerStack.h"

namespace Lumina {

    /**
     * Allows the user to create a Lumina application
     * 
     * Defines the behaviour of a base Lumina application
     * 
     * To be derived and implemented in each new application using the Lumina
     * runtime, including the Editor or other development tools
     */
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
