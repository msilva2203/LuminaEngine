// This code is part of the Lumina Engine and is licensed under the MIT License

#ifndef CORE_EVENT_H
#define CORE_EVENT_H

#pragma once

#include "Core/Core.h"

#include <string>

namespace Lumina {

    /**
     * Represents the exclusive type of an event (the event itself)
     */
    enum class EEventType : uint8
    {
        None = 0,
        WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved, // Window events
        KeyPressed, KeyReleased,                                              // Key events
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled    // Mouse events
    };

    /**
     * Events can be in more than one category, therefore the bit usage
     * (example: Input | Keyboard)
     */
    enum EEventCategory : uint8
    {
        None = 0,
        ApplicationEvent   = 1 << 0,
        InputEvent         = 1 << 1,
        KeyboardEvent      = 1 << 2,
        MouseEvent         = 1 << 3,
        MouseButtonEvent   = 1 << 4
    };

    class LUMINA_API Event
    {
    public:
        virtual EEventType GetEventType() const = 0;
        virtual int32 GetEventCategoryFlags() const = 0;

        inline bool IsInCategory(EEventCategory Category)
        {
            return this->GetEventCategoryFlags() & Category;
        }

        virtual const std::string& ToString() const = 0;

    protected:

    private:
        bool bHandled;

    };

    class LUMINA_API EventDispatcher
    {
    public:

    protected:

    private:

    };

}

#endif /* CORE_EVENT_H */