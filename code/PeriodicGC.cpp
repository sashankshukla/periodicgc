#include "PeriodicGC.h"
#include "RPointer.h"
#include <thread>
#include <chrono>
#include <iostream>

std::list<RPointer<void>*> PeriodicGC::pointers;
std::mutex PeriodicGC::mtx;

void PeriodicGC::registerPointer(RPointer<void>* sp) {
    std::lock_guard<std::mutex> lock(mtx);
    pointers.push_back(sp);
}

void PeriodicGC::unregisterPointer(RPointer<void>* sp) {
    std::lock_guard<std::mutex> lock(mtx);
    pointers.remove(sp);
}

void PeriodicGC::run() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(10)); // Sleep for 10 seconds before checking
        
        std::lock_guard<std::mutex> lock(mtx);

        for (auto it = pointers.begin(); it != pointers.end(); ) {
            if ((*it)->isOrphan()) {
                it = pointers.erase(it);
            } else {
                ++it;
            }
        }
    }
}

void PeriodicGC::getStatus() {
    int i = 0;
    for (auto it = pointers.begin(); it != pointers.end(); ++it)
    {
        std::string status = (*it)->isOrphan() ? "stale" : "active";
        std::cout << i << " : " << status << std::endl;
    }
}
