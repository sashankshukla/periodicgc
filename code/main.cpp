#include "RPointer.h"
#include "PeriodicGC.h"
#include <thread>
#include <iostream>


int main() {
    std::thread gc_thread(PeriodicGC::run);

    RPointer<int> sp1(new int(10));
    RPointer<int> sp2 = sp1;

    gc_thread.join();
    return 0;
}
