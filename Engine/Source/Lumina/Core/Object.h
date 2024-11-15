// This code is part of the Lumina Engine and is licensed under MIT License

#ifndef CORE_OBJECT_H
#define CORE_OBJECT_H

#pragma once

#include "Core/Core.h"

#include <string>

namespace Lumina {

    /**
     * Allows the user to create an integrated object
     * 
     * The base class itself is more useful for just debug purposes
     */
    class LUMINA_API Object
    {
    public:
        Object(const std::string& DebugName);
        virtual ~Object();

        inline const std::string& GetDebugName() { return this->DebugName; }
    protected:

    private:
        std::string DebugName;

    };

}

#endif /* CORE_OBJECT_H */