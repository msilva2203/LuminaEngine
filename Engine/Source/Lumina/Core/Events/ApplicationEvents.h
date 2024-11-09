#ifndef CORE_APPLICATIONEVENTS_H
#define CORE_APPLICATIONEVENTS_H

#pragma once

#include "Core/Event.h"

#include <sstream>

namespace Lumina
{
    class LUMINA_API WindowCloseEvent : public Event
    {
    public:
        DECLARE_EVENT_TYPE(WindowClose)
        DECLARE_EVENT_CATEGORY(CategoryApplicationEvent);

        WindowCloseEvent() {}
    private:

    };

    class LUMINA_API WindowResizeEvent : public Event
    {
    public:
        DECLARE_EVENT_TYPE(WindowResize)
        DECLARE_EVENT_CATEGORY(CategoryApplicationEvent);

        WindowResizeEvent(uint32 Width, uint32 Height) :
            Width(Width),
            Height(Height)
        {
        }

        inline uint32 GetWidth() const { return this->Width; }
        inline uint32 GetHeight() const { return this->Height; }

        virtual std::string ToString() const override
        {
            std::stringstream Stream;
            Stream << GetName() << ": " << GetWidth() << ", " << GetHeight();
            return Stream.str();
        }

    private:
        uint32 Width, Height;
    };

    class LUMINA_API WindowFocusEvent : public Event
    {
    public:
        DECLARE_EVENT_TYPE(WindowFocus)
        DECLARE_EVENT_CATEGORY(CategoryApplicationEvent);

        WindowFocusEvent() {}
    private:

    };

    class LUMINA_API WindowLostFocusEvent : public Event
    {
    public:
        DECLARE_EVENT_TYPE(WindowLostFocus)
        DECLARE_EVENT_CATEGORY(CategoryApplicationEvent);

        WindowLostFocusEvent() {}
    private:

    };

    class LUMINA_API WindowMovedEvent : public Event
    {
    public:
        DECLARE_EVENT_TYPE(WindowMoved)
        DECLARE_EVENT_CATEGORY(CategoryApplicationEvent);

        WindowMovedEvent() {}
    private:

    };
}

#endif /* CORE_APPLICATIONEVENTS_H */