#ifndef CORE_KEYEVENTS_H
#define CORE_KEYEVENTS_H

#pragma once

#include "Events/Event.h"

#include <sstream>

namespace Lumina
{
    class LUMINA_API KeyEvent : public Event
    {
    public:
        DECLARE_EVENT_CATEGORY(CategoryInputEvent | CategoryKeyboardEvent)

        inline int32 GetKeyCode() const { return this->KeyCode; }
        
    protected:
        KeyEvent(int32 KeyCode) :
            KeyCode(KeyCode)
        {}

    private:
        int32 KeyCode;
    };

    class LUMINA_API KeyPressedEvent : public KeyEvent
    {
    public:
        DECLARE_EVENT_TYPE(KeyPressed)

        KeyPressedEvent(int32 KeyCode, bool bRepeat) :
            KeyEvent(KeyCode),
            bRepeat(bRepeat)
        {}

        inline bool IsRepeat() const { return this->bRepeat; }

        virtual std::string ToString() const override
        {
            std::stringstream Stream;
            Stream << GetName() << ": " << GetKeyCode();
            if (IsRepeat()) {
                Stream << " (Repeat)";
            }
            return Stream.str();
        }

    private:
        bool bRepeat;
    };

    class LUMINA_API KeyReleasedEvent : public KeyEvent
    {
    public:
        DECLARE_EVENT_TYPE(KeyReleased)

        KeyReleasedEvent(int32 KeyCode) :
            KeyEvent(KeyCode)
        {}

        virtual std::string ToString() const override
        {
            std::stringstream Stream;
            Stream << GetName() << ": " << GetKeyCode();
            return Stream.str();
        }

    };
}

#endif /* CORE_KEYEVENTS_H */