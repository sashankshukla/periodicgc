#pragma once

#include <list>
#include <mutex>

class PeriodicGC {
private:
    static std::list<RPointer<void>*> pointers;
    static std::mutex mtx;

public:
    static void registerPointer(RPointer<void>* sp);
    static void unregisterPointer(RPointer<void>* sp);
    static void run();
    static void getStatus();
};
