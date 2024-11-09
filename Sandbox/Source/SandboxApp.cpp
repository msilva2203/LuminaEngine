#include "Lumina.h"
#include "Core/Array.h"

using namespace Lumina;

class MyLayer : public Lumina::Layer
{
public:
    virtual void OnAttach() override
    {
        LUMINA_INFO("MyLayer::OnAttach");

        TArray<int32> MyArray;
        MyArray.Init(7, 50);
    }

    virtual void OnUpdate(float DeltaTime) override
    {
        //LUMINA_INFO("MyLayer::OnUpdate({0})", DeltaTime);
        //LUMINA_ASSERT((1 > 3), "1 is not greater than 3!");

        LUMINA_ASSERT(1 == 3, "1 is not equal to 3");
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
