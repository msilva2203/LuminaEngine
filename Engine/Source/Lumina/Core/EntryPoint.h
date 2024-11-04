// This code is part of the Lumina Engine and is licensed under MIT License

#ifndef CORE_ENTRYPOINT_H
#define CORE_ENTRYPOINT_H

#pragma once

#ifdef LUMINA_PLATFORM_WINDOWS

    extern Lumina::Application* Lumina::CreateApplication();

    int main(int argc, char** argv)
    {
        Lumina::Core::Init();
        Lumina::Application* App = Lumina::CreateApplication();
        App->Run();
        delete App;
    }

#endif /* LUMINA_PLATFORM_WINDOWS */

#ifdef LUMINA_PLATFORM_LINUX

    extern Lumina::Application* Lumina::CreateApplication();

    int main(int argc, char** argv)
    {
        Lumina::Core::Init();
        Lumina::Application* App = Lumina::CreateApplication();
        App->Run();
        delete App;
    }

#endif /* LUMINA_PLATFORM_LINUX */

#endif /* CORE_ENTRYPOINT_H */
