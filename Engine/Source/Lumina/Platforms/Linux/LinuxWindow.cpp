#include "LinuxWindow.h"

#ifdef LUMINA_PLATFORM_LINUX

namespace Lumina {

    Window* Window::Create(const FWindowSettings& WindowSettings)
    {
        return new LinuxWindow(WindowSettings);
    }

    LinuxWindow::LinuxWindow(const FWindowSettings& WindowSettings)
    {

    }

    LinuxWindow::~LinuxWindow()
    {

    }


}

#endif /* LUMINA_PLATFORM_LINUX */