#pragma once


class ReferenceCounter {

    private:

        int counter;

    public:

        ReferenceCounter();

        int increment();
        int decrement();

        int get();
};