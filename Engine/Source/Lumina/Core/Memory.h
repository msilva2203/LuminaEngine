#ifndef CORE_MEMORY_H
#define CORE_MEMORY_H

#pragma once

#include "Core/Core.h"

#include <memory>

namespace Lumina {

    template <typename T>
    using TRef = std::shared_ptr<T>;

    template <typename T>
    using TScope = std::unique_ptr<T>;

}

#endif /* CORE_MEMORY_H */