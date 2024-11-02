#include "Lumina.h"
#include "Core/Array.h"

using namespace Lumina;

class SandboxApp : public Lumina::FApplication
{
    public:
    SandboxApp()
    {

    }

    ~SandboxApp()
    {

    }

};

Lumina::FApplication* Lumina::CreateApplication()
{
    LUMINA_INFO("Application created");

    TArray<int> MyArray;
    MyArray.Init(7, 10);

    for (const auto& Elem : MyArray)
    {
        LUMINA_ERROR("{0}", Elem);
    }

    return new SandboxApp;
}
