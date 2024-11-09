#ifndef PLATFORMS_LINUXWINDOW_H
#define PLATFORMS_LINUXWINDOW_H

#pragma once

#include "Core/Core.h"
#include "Core/Window.h"

#ifdef LUMINA_PLATFORM_LINUX

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