#pragma once

#include "ReferenceCounter.hpp"


template<typename T>
SmartPointer<T>::SmartPointer(T* pointer) {

    this->pointer = pointer;
    counter = new ReferenceCounter();
    counter->increment();
}

template<typename T>
SmartPointer<T>::SmartPointer(const SmartPointer<T>& other) {

    pointer = other.pointer;
    counter = other.counter;
    counter->increment();
}

template<typename T>
SmartPointer<T>::~SmartPointer() {

    if (counter->decrement() == 0) {

        delete pointer;
        delete counter;
    }
}

template<typename T>
T& SmartPointer<T>::operator*() {

    return *pointer;
}

template<typename T>
T* SmartPointer<T>::operator->() {

    return pointer;
}

template<typename T>
void SmartPointer<T>::operator=(const SmartPointer<T>& other) {

    if (pointer != nullptr && counter->decrement() == 0) {

        delete pointer;
        delete counter;
    }

    pointer = other.pointer;
    counter = other.counter;
    counter->increment();
}