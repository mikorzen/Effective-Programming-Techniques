#pragma once

#include "ReferenceCounter.hpp"


template <typename T>
class SmartPointer {

    private: 

        T* pointer;
        ReferenceCounter *counter;

    public: 

        SmartPointer(T* pointer);
        SmartPointer(const SmartPointer<T>& other);
        ~SmartPointer();

        T& operator*();
        T* operator->();

        void operator=(const SmartPointer<T>& other);
};


#include "SmartPointer.tpp"