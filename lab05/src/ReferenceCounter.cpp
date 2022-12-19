#include "ReferenceCounter.hpp"


ReferenceCounter::ReferenceCounter() {

    counter = 0;
}

int ReferenceCounter::increment() {

    return ++counter;
}

int ReferenceCounter::decrement() {

    return --counter;
}

int ReferenceCounter::get() {

    return counter;
}