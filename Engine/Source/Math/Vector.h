#pragma once

#include "Types.h"

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
