#pragma once

#include <utility>

namespace LM
{
    template <typename T>
    class TArray
    {
        public:
        TArray();
        TArray(T Element);
        TArray(T Element, unsigned int Num);
        ~TArray();

        void Init(T Element, unsigned int Num);
        void Add(T Element);
        bool Find(T Element, unsigned int& OutIndex) const;
        bool Remove(T Element, bool bResize = true);
        bool Remove(unsigned int Index, bool bResize = true);
        T Get(unsigned int Index) const;
        T& GetReference(unsigned int Index);

        protected:

        private:
        void Expand();
        void Shrink();

        T* Buffer;
        unsigned int Capacity;
        unsigned int Size;
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
    TArray<T>::TArray(T Element, unsigned int Num) :
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
    void TArray<T>::Init(T Element, unsigned int Num)
    {
        if (Num == 0) return;

        delete[] this->Buffer;

        this->Capacity = Num;
        this->Size = Num;
        this->Buffer = new T[Num];
        for (unsigned int i = 0; i < Num; i++)
        {
            this->Buffer[i] = Element;
        }
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
    bool TArray<T>::Find(T Element, unsigned int& OutIndex) const
    {
        for (OutIndex = 0; OutIndex < this->Size; OutIndex++)
        {
            if (this->Buffer[OutIndex] == Element) return true;
        }
        return false;
    }

    template<typename T>
    bool TArray<T>::Remove(T Element, bool bResize)
    {
        unsigned int Index;
        if (this->Find(Element, Index))
        {
            return this->Remove(Index, bResize);
        }
        return false;
    }

    template<typename T>
    bool TArray<T>::Remove(unsigned int Index, bool bResize)
    {
        if (Index >= this->Size) return false;

        for (unsigned int i = Index; i < this->Size - 1; i++)
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
    T TArray<T>::Get(unsigned int Index) const
    {
        return this->Buffer[Index];
    }

    template<typename T>
    T& TArray<T>::GetReference(unsigned int Index)
    {
        return this->Buffer[Index];
    }

    template<typename T>
    void TArray<T>::Expand()
    {
        if (this->Capacity == 0)
        {
            this->Capacity = 1;
        }
        this->Capacity *= 2;
        T* TempBuffer = this->Buffer;
        this->Buffer = new T[this->Capacity];

        for (unsigned int i = 0; i < this->Size; i++)
        {
            this->Buffer[i] = std::move(TempBuffer[i]);
        }

        delete[] TempBuffer;
    }

    template<typename T>
    void TArray<T>::Shrink()
    {
        if (this->Capacity <= 1) return;
        if (this->Size < this->Capacity / 2)
        {
            this->Capacity /= 2;
            T* TempBuffer = this->Buffer;
            this->Buffer = new T[this->Capacity];

            for (unsigned int i = 0; i < this->Size; i++)
            {
                this->Buffer[i] = std::move(TempBuffer[i]);
            }

            delete[] TempBuffer;
        }
    }

}
