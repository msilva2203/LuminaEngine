#ifndef PLATFORMS_LINUXWINDOW_H
#define PLATFORMS_LINUXWINDOW_H

#pragma once

#ifdef LUMINA_PLATFORM_LINUX

#include "Core/Core.h"
#include "Core/Window.h"

namespace Lumina {

    class LUMINA_API LinuxWindow : public Window
    {
    public:
        LinuxWindow(const FWindowSettings& WindowSettings);
        ~LinuxWindow();

    };

}

#endif /* LUMINA_PLATFORM_LINUX */

#endif /* PLATFORMS_LINUXWINDOW_H */