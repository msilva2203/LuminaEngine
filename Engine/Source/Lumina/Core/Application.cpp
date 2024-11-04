// This code is part of the Lumina Engine and is licensed under MIT License

#include "Application.h"

#include "Core/Time.h"

namespace Lumina {

    Application::Application()
    {
        FWindowSettings WindowSettings;
        WindowSettings.Title = "Lumina Window";
        WindowSettings.Width = 1280;
        WindowSettings.Height = 720;
        WindowSettings.bVSyncEnabled = false;

        AppWindow = Window::Create(WindowSettings);
    }

    Application::~Application()
    {
        delete AppWindow;
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

            // Update layers in layer stack
            for (auto& StackLayer : MainLayerStack)
            {
                StackLayer->OnUpdate(DeltaTime);
            }

            // Update window
            AppWindow->OnUpdate();

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
