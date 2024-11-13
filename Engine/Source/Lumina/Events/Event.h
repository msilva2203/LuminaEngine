// This code is part of the Lumina Engine and is licensed under the MIT License

#ifndef CORE_EVENT_H
#define CORE_EVENT_H

#pragma once

#include "Core/Core.h"

#include <iostream>
#include <string>
#include <functional>

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
     * Represents the category of an event
     * 
     * Events can be in more than one category, therefore the bit usage
     * (example: CategoryInput | CategoryKeyboardEvent)
     */
    enum EEventCategory : uint8
    {
        CategoryNone = 0,
        CategoryApplicationEvent   = 1 << 0,
        CategoryInputEvent         = 1 << 1,
        CategoryKeyboardEvent      = 1 << 2,
        CategoryMouseEvent         = 1 << 3,
        CategoryMouseButtonEvent   = 1 << 4
    };

    class LUMINA_API Event
    {
        friend class EventDispatcher;
    public:
        virtual EEventType GetEventType() const = 0;
        virtual int32 GetEventCategoryFlags() const = 0;
        virtual const char* GetName() const = 0;

        inline bool IsInCategory(EEventCategory Category)
        {
            return this->GetEventCategoryFlags() & Category;
        }

        virtual std::string ToString() const { return GetName(); }

        friend std::ostream& operator<<(std::ostream& Ostream, const Event& InEvent)
        {
            return Ostream << InEvent.ToString();
        }

    protected:

    private:
        bool bHandled;

    };

    class LUMINA_API EventDispatcher
    {
        template <typename T>
        using EventFunction = std::function<bool(T&)>;
    public:
        EventDispatcher(Event& InEvent) :
            EventToDispatch(InEvent)
        {}

        template <typename T>
        bool Dispatch(EventFunction<T> Function)
        {
            if (T::GetStaticEventType() == EventToDispatch.GetEventType())
            {
                EventToDispatch.bHandled = Function(*(T*)&EventToDispatch);
                return true;
            }
            return false;
        }

    private:
        Event& EventToDispatch;

    };

    #define DECLARE_EVENT_TYPE(Type) \
        static EEventType GetStaticEventType() { return EEventType::Type; } \
        virtual EEventType GetEventType() const override { return GetStaticEventType(); } \
        virtual const char* GetName() const override { return #Type; } \

    #define DECLARE_EVENT_CATEGORY(CategoryFlags) \
        virtual int32 GetEventCategoryFlags() const override { return CategoryFlags; } \

}

#define BIND_EVENT(Function, Object) std::bind(&Function, Object, std::placeholders::_1)

#endif /* CORE_EVENT_H */