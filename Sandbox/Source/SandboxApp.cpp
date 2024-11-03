#include "Lumina.h"
#include "Core/Array.h"

using namespace Lumina;

class MyLayer : public Lumina::Layer
{
public:
    virtual void OnUpdate(float DeltaTime)
    {
        LUMINA_INFO("MyLayer::OnUpdate");
    }

    virtual void OnRender()
    {
        LUMINA_TRACE("MyLayer::OnRender");
    }

private:

};

class SandboxApp : public Lumina::Application
{
    public:
    SandboxApp()
    {
        PushLayer(new MyLayer);
    }

    ~SandboxApp()
    {

    }

};

Lumina::Application* Lumina::CreateApplication()
{
    return new SandboxApp;
}
