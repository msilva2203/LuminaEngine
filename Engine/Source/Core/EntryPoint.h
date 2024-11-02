#ifndef CORE_ENTRYPOINT_H
#define CORE_ENTRYPOINT_H

#ifdef LUMINA_PLATFORM_WINDOWS

extern Lumina::FApplication* Lumina::CreateApplication();

int main(int argc, char** argv)
{
    Lumina::FApplication* App = Lumina::CreateApplication();
    App->Run();
    delete App;
}

#endif /* LUMINA_PLATFORM_WINDOWS */

#ifdef LUMINA_PLATFORM_LINUX

extern Lumina::FApplication* Lumina::CreateApplication();

int main(int argc, char** argv)
{
    Lumina::FApplication* App = Lumina::CreateApplication();
    App->Run();
    delete App;
}

#endif /* LUMINA_PLATFORM_LINUX */

#endif /* CORE_ENTRYPOINT_H */