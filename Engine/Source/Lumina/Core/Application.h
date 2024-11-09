// This code is part of the Lumina Engine and is licensed under MIT License

#ifndef CORE_APPLICATION_H
#define CORE_APPLICATION_H

#pragma once

#include "Core/Core.h"
#include "Core/LayerStack.h"
#include "Core/Window.h"

namespace Lumina {

    /**
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

        static Application* GetInstance();

        static Application* Instance;
    
    protected:
    
    private:
        bool bRunning;
        float32 LastFrameTime;
        LayerStack MainLayerStack;
        Window* AppWindow;
    
    };

    // To be defined in the Sandbox application
    Application* CreateApplication();
}

#endif /* CORE_APPLICATION_H */
