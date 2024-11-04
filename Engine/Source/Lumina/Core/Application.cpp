// This code is part of the Lumina Engine and is licensed under MIT License

#include "Application.h"

#include "Core/Time.h"

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
        LastFrameTime = 0.0f;
    }

    void Application::Run()
    {
        OnInit();

        while (bRunning)
        {
            float32 CurrentTime = Time::GetElapsedSeconds();
            float32 DeltaTime = CurrentTime - LastFrameTime;

            for (auto& StackLayer : MainLayerStack)
            {
                StackLayer->OnUpdate(DeltaTime);
            }

            LastFrameTime = CurrentTime;
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
