// This code is part of the Lumina Engine and is licensed under MIT License

#ifndef CORE_APPLICATION_H
#define CORE_APPLICATION_H

#pragma once

#include "Core/Core.h"
#include "Core/LayerStack.h"
#include "Core/Window.h"
#include "Events/ApplicationEvents.h"
#include "Events/KeyEvents.h"
#include "Events/MouseEvents.h"
#include "Utility/Time.h"

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
        void OnEvent(Event& InEvent);

        void PushLayer(Layer* InLayer);
        void PopLayer(Layer* InLayer);

        static Application* GetInstance();
    
    protected:
    
    private:
        bool OnWindowClose(WindowCloseEvent& InEvent);

        bool bRunning;
        Time AppTime;
        float32 LastFrameTime;
        LayerStack MainLayerStack;
        Window* AppWindow;
    
        static Application* Instance;
    };

    // To be defined in the Sandbox application
    Application* CreateApplication();
}

#endif /* CORE_APPLICATION_H */
