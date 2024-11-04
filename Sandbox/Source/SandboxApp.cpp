#include "Lumina.h"
#include "Core/Array.h"

using namespace Lumina;

class MyLayer : public Lumina::Layer
{
public:
    virtual void OnUpdate(float DeltaTime) override
    {
        LUMINA_INFO("MyLayer::OnUpdate({0})", DeltaTime);
        LUMINA_ASSERT((1 > 3), "1 is not greater than 3!");
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
