#include "PeriodicGC.h"

template <typename T>
RPointer<T>::RPointer(T* p) : ptr(p), counter(new RefCounter()) {
    PeriodicGC::registerPointer((RPointer<void>*)this);
}