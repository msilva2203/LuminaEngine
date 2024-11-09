// This code is part of the Lumina Engine and is licensed under MIT License

#ifndef CORE_ARRAY_H
#define CORE_ARRAY_H

#include "Core/Core.h"

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

    /**
     * Initializes the array with a specified number of elements, each initialized to the specified value
     * @param Element The element that the array will be filled with
     * @param Num The number of elements
     */
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

    /**
     * Resets the array to an empty state, with an option to release allocated memory
     * @param bDeallocate Deallocate or not memory used in array
     */
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

    /**
     * Add a new element to the array, allocating more memory if needed
     * @param Element Element to add to the array
     */
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

    /**
     * Finds the index of the first occurrence of an element in the array
     * @param Element The element to search for
     * @param OutIndex Reference of the returned index
     * @returns True if the element was found, false otherwise
     */
    template<typename T>
    bool TArray<T>::Find(T Element, uint32& OutIndex) const
    {
        for (OutIndex = 0; OutIndex < this->Size; OutIndex++)
        {
            if (this->Buffer[OutIndex] == Element) return true;
        }
        return false;
    }

    /**
     * Finds the index of the last occurrence of an element in the array
     * @param Element The element to search for
     * @param OutIndex Reference of the returned index
     * @returns True if the element was found, false otherwise
     */
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

    /**
     * Check if element is present in the array
     * @param Element The element to check
     * @returns True if the array contains the element, false otherwise
     */
    template<typename T>
    bool TArray<T>::Contains(T Element) const
    {
        uint32 Index;
        return Find(Element, Index);
    }

    /**
     * Removes the first ocurrence of an element in the array
     * @param Element The element to remove from the array
     * @param bResize Specifies if the array should be resize when possible
     * @returns True if an element was removed, false otherwise
     */
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

    /**
     * Removes the last ocurrence of an element in the array
     * @param Element The element to remove from the array
     * @param bResize Specifies if the array should be resize when possible
     * @returns True if an element was removed, false otherwise
     */
    template<typename T>
    bool TArray<T>::RemoveLast(T Element, bool bResize)
    {
        uint32 Index;
        if (this->FindLast(Element, Index)) {
            return this->RemoveAt(Index, bResize);
        }
        return false;
    }

    /**
     * Removes the element of the array at the specified index
     * @param Index The index of the element to remove from the array
     * @param bResize Specifies if the array should be resize when possible
     * @returns True if an element was removed, false otherwise
     */
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

    /**
     * Removes all ocurrences of an element from the array
     * @param Element The element to remove from the array
     * @param bResize Specifies if the array should be resize when possible
     * @returns True if an element was removed, false otherwise
     */
    template<typename T>
    bool TArray<T>::RemoveAll(T Element, bool bResize)
    {
        // TODO: Define the function RemoveAll(...)
    }

    /**
     * Get the reference to the element from the array at specified index
     * @param Index The index of the element
     * @returns The reference to the element
     */
    template<typename T>
    T& TArray<T>::At(uint32 Index)
    {
        return this->Buffer[Index];
    }

    /**
     * Set the size of the array, stripping or filling the array according to the new size
     * @param Num The new size of the array
     */
    template<typename T>
    void TArray<T>::SetNum(uint32 Num)
    {
        ReAllocate(Num, true);
    }

    /**
     * Get the number of elements in the array
     * @returns The number of elements
     */
    template<typename T>
    uint32 TArray<T>::Num() const
    {
        return this->Size;
    }

    /**
     * Get the raw pointer to the data in the array
     * @returns Pointer to the data
     */
    template<typename T>
    T* TArray<T>::GetData() const
    {
        return this->Buffer;
    }

    /**
     * Validate if the specified index is in bounds of the size of the array
     * @param Index The index to validate
     * @returns True if the index is valid, false otherwise
     */
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
