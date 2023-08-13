#pragma once

#include "RefCounter.h"
#include "PeriodicGC.h" // Forward declaration

template <typename T>
class RPointer {
private:
    T* ptr;
    RefCounter* counter;

public:
    RPointer(T* p);
    RPointer(const RPointer<T>& sp);
    ~RPointer();
    RPointer<T>& operator=(const RPointer<T>& sp);
    T& operator*() const;
    T* operator->() const;
    bool isOrphan() {
        return counter->getRefCount() == 0;
    }
};

#include "RPointer.tpp" // Include template definitions
