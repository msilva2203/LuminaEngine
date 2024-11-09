#ifndef CORE_MOUSEEVENTS_H
#define CORE_MOUSEEVENTS_H

#pragma once

#include "Core/Event.h"

#include <sstream>

namespace Lumina
{
    class LUMINA_API MouseEvent : public Event
    {
    public:
        DECLARE_EVENT_CATEGORY(CategoryInputEvent | CategoryMouseEvent)

    };

    class LUMINA_API MouseButtonEvent : public MouseEvent
    {
    public:
        DECLARE_EVENT_CATEGORY(CategoryInputEvent | CategoryMouseEvent | CategoryMouseButtonEvent)

        inline int32 GetKeyCode() const { return this->KeyCode; }

        virtual std::string ToString() const override
        {
            std::stringstream Stream;
            Stream << GetName() << ": " << GetKeyCode();
            return Stream.str();
        }

    protected:
        MouseButtonEvent(int32 KeyCode) :
            KeyCode(KeyCode)
        {}

    private:
        int32 KeyCode;
    };

    class LUMINA_API MouseButtonPressedEvent : public MouseButtonEvent
    {
    public:
        DECLARE_EVENT_TYPE(MouseButtonPressed)

        MouseButtonPressedEvent(int32 KeyCode) :
            MouseButtonEvent(KeyCode)
        {}
    };

    class LUMINA_API MouseButtonReleasedEvent : public MouseButtonEvent
    {
    public:
        DECLARE_EVENT_TYPE(MouseButtonReleased)

        MouseButtonReleasedEvent(int32 KeyCode) :
            MouseButtonEvent(KeyCode)
        {}
    };

    class LUMINA_API MouseMovedEvent : public MouseEvent
    {
    public:
        DECLARE_EVENT_TYPE(MouseMoved)

        MouseMovedEvent(float32 X, float32 Y) :
            X(X),
            Y(Y)
        {}

        inline float32 GetX() const { return this->X; }
        inline float32 GetY() const { return this->Y; }

        virtual std::string ToString() const override
        {
            std::stringstream Stream;
            Stream << GetName() << ": " << GetX() << ", " << GetY();
            return Stream.str();
        }

    private:
        float32 X, Y; // TODO: Replace with Vec2
    };

    class LUMINA_API MouseScrolledEvent : public MouseEvent
    {
    public:
        DECLARE_EVENT_TYPE(MouseScrolled)

        MouseScrolledEvent(float32 DeltaX, float32 DeltaY) :
            DeltaX(DeltaX),
            DeltaY(DeltaY)
        {}

        inline float32 GetDeltaX() const { return this->DeltaX; }
        inline float32 GetDeltaY() const { return this->DeltaY; }

        virtual std::string ToString() const override
        {
            std::stringstream Stream;
            Stream << GetName() << ": " << GetDeltaX() << ", " << GetDeltaY();
            return Stream.str();
        }

    private:
        float32 DeltaX, DeltaY; // TODO: Replace with Vec2
    };
}

#endif /* CORE_MOUSEEVENTS_H */