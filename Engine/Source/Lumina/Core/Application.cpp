#include "Application.h"

namespace Lumina {

    Application::Application()
    {
    }

    Application::~Application()
    {
    }

    void Application::OnInit()
    {
        bRunning = true;
    }

    void Application::Run()
    {
        OnInit();
        while (bRunning)
        {
            MainLayerStack.OnUpdate(0.0f);
            MainLayerStack.OnRender();
        }
    }

    void Application::PushLayer(Layer* InLayer)
    {
        MainLayerStack.PushLayer(InLayer);
    }

    void Application::PopLayer(Layer* InLayer)
    {
        MainLayerStack.PopLayer(InLayer);
    }

}
