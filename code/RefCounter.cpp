#include "RefCounter.h"

RefCounter::RefCounter() : count(1) {}

void RefCounter::increment() { count++; }

void RefCounter::decrement() { --count; }

int RefCounter::getRefCount() { return count; }
