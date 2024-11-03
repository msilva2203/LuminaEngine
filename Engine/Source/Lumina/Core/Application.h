#ifndef CORE_APPLICATION_H
#define CORE_APPLICATION_H

#include "Core.h"
#include "LayerStack.h"

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
        LayerStack MainLayerStack;
    
    };

    // To be defined in the Sandbox application
    Application* CreateApplication();
}

#endif /* CORE_APPLICATION_H */