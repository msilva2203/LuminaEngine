#ifndef LUMINA_VECTOR_H
#define LUMINA_VECTOR_H

#pragma once

#include "Utility/Types.h"

template<typename T>
class TVector
{
    public:
    T x, y, z;

    protected:

    private:

};

template<typename T>
class TVector2D
{
    public:
    T x, y;

    protected:

    private:

};

using FVector = TVector<float32>;
using FVector2D = TVector2D<float32>;

#endif /* LUMINA_VECTOR_H */