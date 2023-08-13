#pragma once

class RefCounter {
private:
    int count;

public:
    RefCounter();
    void increment();
    void decrement();
    int getRefCount();
};
