#include "Lumina.h"

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
    return new SandboxApp;
}
