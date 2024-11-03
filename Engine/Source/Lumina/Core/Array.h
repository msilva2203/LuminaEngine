#ifndef CORE_ARRAY_H
#define CORE_ARRAY_H

#include "Core.h"

#include <utility>
#include <iterator>

namespace Lumina {

    template <typename T>
    class TArray
    {
    public:
        using Iterator = T*;
        using ConstIterator = const T*;

        TArray();
        TArray(T Element);
        TArray(T Element, uint32 Num);
        ~TArray();

        void Init(T Element, uint32 Num);
        void Clear(bool bDeallocate = true);
        void Add(T Element);
        bool Find(T Element, uint32& OutIndex) const;
        bool FindLast(T Element, uint32& OutIndex) const;
        bool Contains(T Element) const;
        bool Remove(T Element, bool bResize = true);
        bool RemoveLast(T Element, bool bResize = true);
        bool RemoveAt(uint32 Index, bool bResize = true);
        bool RemoveAll(T Element, bool bResize = true);
        T& At(uint32 Index);
        void SetNum(uint32 Num);
        uint32 Num() const;
        T* GetData() const;
        bool IsValidIndex(uint32 Index) const;

        T& operator[](uint32 Index)
        {
            return this->At(Index);
        }
        const T& operator[](uint32 Index) const
        {
            return this->At(Index);
        }
        TArray<T>& operator=(const TArray<T>& Other)
        {
            delete[] this->Buffer;
            this->Buffer = nullptr;
            this->Capacity = 0;
            this->Size = 0;

            if (Other.Size > 0) {
                this->Init(Other.Buffer[0], Other.Size);
                for (uint32 i = 0; i < Other.Size; i++)
                {
                    this->Buffer[i] = Other.Buffer[i];
                }
            }
            return *this;
        }

        Iterator begin() { return this->Buffer; }
        Iterator end() { return this->Buffer + this->Size; }
        ConstIterator begin() const { return this->Buffer; }
        ConstIterator end() const { return this->Buffer + this->Size; }

    protected:

    private:
        void Expand();
        void Shrink();
        void ReAllocate(uint32 NewCapacity, bool bForce = false);

        T* Buffer;
        uint32 Capacity;
        uint32 Size;
    };

    template<typename T>
    TArray<T>::TArray() :
        Buffer(nullptr),
        Capacity(0),
        Size(0)
    {
    }

    template<typename T>
    TArray<T>::TArray(T Element) :
        Buffer(nullptr),
        Capacity(0),
        Size(0)
    {
        this->Init(Element, 1);
    }

    template<typename T>
    TArray<T>::TArray(T Element, uint32 Num) :
        Buffer(nullptr),
        Capacity(0),
        Size(0)
    {
        this->Init(Element, Num);
    }

    template<typename T>
    TArray<T>::~TArray()
    {
        delete[] this->Buffer;
    }

    template<typename T>
    void TArray<T>::Init(T Element, uint32 Num)
    {
        if (Num == 0) return;

        delete[] this->Buffer;

        this->Capacity = Num;
        this->Size = Num;
        this->Buffer = new T[Num];
        for (uint32 i = 0; i < Num; i++)
        {
            this->Buffer[i] = Element;
        }
    }

    template<typename T>
    void TArray<T>::Clear(bool bDeallocate)
    {
        if (bDeallocate) {
            delete[] this->Buffer;
            this->Buffer = nullptr;
            this->Capacity = 0;
        } else {
            if (this->Buffer != nullptr) {
                for (uint32 i = 0; i < this->Size; i++)
                {
                    this->Buffer[i] = 0;
                }
            }
        }
        this->Size = 0;
    }

    template<typename T>
    void TArray<T>::Add(T Element)
    {
        if (this->Size >= this->Capacity)
        {
            this->Expand();
        }
        this->Buffer[Size] = Element;
        this->Size++;
    }

    template<typename T>
    bool TArray<T>::Find(T Element, uint32& OutIndex) const
    {
        for (OutIndex = 0; OutIndex < this->Size; OutIndex++)
        {
            if (this->Buffer[OutIndex] == Element) return true;
        }
        return false;
    }

    template<typename T>
    bool TArray<T>::FindLast(T Element, uint32& OutIndex) const
    {
        if (this->Size == 0) return false;
        for (OutIndex = this->Size - 1; OutIndex >= 0; OutIndex--)
        {
            if (this->Buffer[OutIndex] == Element) {
                return true;
            }
        }
        return false;
    }

    template<typename T>
    bool TArray<T>::Contains(T Element) const
    {
        uint32 Index;
        return Find(Element, Index);
    }

    template<typename T>
    bool TArray<T>::Remove(T Element, bool bResize)
    {
        uint32 Index;
        if (this->Find(Element, Index))
        {
            return this->RemoveAt(Index, bResize);
        }
        return false;
    }

    template<typename T>
    bool TArray<T>::RemoveLast(T Element, bool bResize)
    {
        uint32 Index;
        if (this->FindLast(Element, Index)) {
            return this->RemoveAt(Index, bResize);
        }
        return false;
    }

    template<typename T>
    bool TArray<T>::RemoveAt(uint32 Index, bool bResize)
    {
        if (Index >= this->Size) return false;

        for (uint32 i = Index; i < this->Size - 1; i++)
        {
            this->Buffer[i] = std::move(this->Buffer[i + 1]);
        }

        this->Size--;

        if (bResize)
        {
            this->Shrink();
        }
        return true;
    }

    template<typename T>
    bool TArray<T>::RemoveAll(T Element, bool bResize)
    {
        // TODO
    }

    template<typename T>
    T& TArray<T>::At(uint32 Index)
    {
        return this->Buffer[Index];
    }

    template<typename T>
    void TArray<T>::SetNum(uint32 Num)
    {
        ReAllocate(Num, true);
    }

    template<typename T>
    uint32 TArray<T>::Num() const
    {
        return this->Size;
    }

    template<typename T>
    T* TArray<T>::GetData() const
    {
        return this->Buffer;
    }

    template<typename T>
    bool TArray<T>::IsValidIndex(uint32 Index) const
    {
        return Index < this->Size;
    }

    template<typename T>
    void TArray<T>::Expand()
    {
        if (this->Capacity == 0)
        {
            this->Capacity = 1;
        }
        ReAllocate(this->Capacity * 2);
    }

    template<typename T>
    void TArray<T>::Shrink()
    {
        if (this->Capacity <= 1) return;
        if (this->Size < this->Capacity / 2)
        {
            ReAllocate(this->Capacity / 2);
        }
    }

    template<typename T>
    void TArray<T>::ReAllocate(uint32 NewCapacity, bool bForce)
    {
        if (NewCapacity > this->Size || bForce) {
            if (this->Size > NewCapacity) {
                this->Size = NewCapacity;
            }
            this->Capacity = NewCapacity;
            T* TempBuffer = this->Buffer;
            this->Buffer = new T[this->Capacity];

            for (uint32 i = 0; i < this->Size; i++)
            {
                this->Buffer[i] = std::move(TempBuffer[i]);
            }

            delete[] TempBuffer;
        }
    }
    
}

#endif /* CORE_ARRAY_H */
