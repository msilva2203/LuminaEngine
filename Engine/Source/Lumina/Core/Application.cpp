// This code is part of the Lumina Engine and is licensed under MIT License

#include "Application.h"

#include "Core/Log.h"
#include "Utility/Time.h"

#include "GLFW/glfw3.h"

namespace Lumina {

    // The singleton instance of application
    Application* Application::Instance = nullptr;

    /**
     * Constructs a base application, initializing it's member variables
     */
    Application::Application() :
        bRunning(false),
        AppTime(Time()),
        LastFrameTime(0.0f),
        MainLayerStack(LayerStack()),
        AppWindow(nullptr)
    {
    }

    /**
     * Destructs a base application, releasing any used memory
     */
    Application::~Application()
    {
        delete AppWindow;
    }

    /**
     * Initializes the overall state of the application
     */
    void Application::OnInit()
    {
        LUMINA_CORE_INFO("Initializing application...");
        LUMINA_CORE_ASSERT(GetInstance() == nullptr, "An application instance is already initialized");
        Instance = this; // Sets the current instance of application to this object

        // Creates a window
        FWindowSettings WindowSettings;
        WindowSettings.Title = "Lumina Engine";
        WindowSettings.Width = 1280;
        WindowSettings.Height = 720;
        WindowSettings.bVSyncEnabled = false;
        this->AppWindow = Window::Create(WindowSettings);
        this->AppWindow->SetEventCallback(BIND_EVENT(Application::OnEvent, this));

        this->bRunning = true;
        this->LastFrameTime = 0.0f;

        LUMINA_CORE_INFO("Application initialized");
    }

    /**
     * Runs the application, serving as the main loop of the program
     */
    void Application::Run()
    {
        OnInit();

        while (bRunning)
        {
            float32 CurrentTime = this->AppTime.GetElapsedSeconds();
            float32 DeltaTime = CurrentTime - this->LastFrameTime;

            // Update layers in layer stack
            for (auto& CurrentLayer : this->MainLayerStack)
            {
                CurrentLayer->OnUpdate(DeltaTime);
            }

            // Rendering
            glClear(GL_COLOR_BUFFER_BIT);
            glClearColor(0.05f, 0.05f, 0.05f, 1.0f);

            // Crashing on linux
            //glBegin(GL_TRIANGLES);
            //glVertex2f(-0.50f, -0.50f);
            //glVertex2f( 0.50f, -0.50f);
            //glVertex2f( 0.00f,  0.50f);
            //glEnd();

            // Update window
            this->AppWindow->OnUpdate();

            this->LastFrameTime = CurrentTime;
        }
    }

    /**
     * Handles events received from various sources
     * @param InEvent The event received
     */
    void Application::OnEvent(Event& InEvent)
    {
        // TODO: Propagate events to layers
        LUMINA_CORE_TRACE("{0}", InEvent.ToString());

        EventDispatcher Dispatcher(InEvent);
        Dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT(Application::OnWindowClose, this));
    }

    /**
     * Pushes a new layer to the main layer stack
     * @param InLayer The layer to push
     */
    void Application::PushLayer(Layer* InLayer)
    {
        this->MainLayerStack.PushLayer(InLayer);
    }

    /**
     * Pops a layer from the layer stack
     * @param InLayer The layer to pop
     */
    void Application::PopLayer(Layer* InLayer)
    {
        this->MainLayerStack.PopLayer(InLayer);
    }

    /**
     * Get the singleton instance of current application
     * @returns The pointer to current application
     */
    Application* Application::GetInstance()
    {
        return Instance;
    }

    /**
     * Callback from the window close event
     * @param InEvent The event
     */
    bool Application::OnWindowClose(WindowCloseEvent& InEvent)
    {
        this->bRunning = false;
        return true;
    }

}
