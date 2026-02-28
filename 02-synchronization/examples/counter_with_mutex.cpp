#include <iostream>
#include <thread>

using namespace std;

/*
    Lock guard prevents a race condition. It automatically locks a mutex, the unlocks it when it goes out
    of scope. You don't have to manually unlock and lock.

    Why don't we have to lock the for loop? Each thread has it's own stack and local variables. They execute 
    the function independently.

*/

int counter = 0;
mutex mtx;

void increment(string thread) {
    for(int i = 0; i < 1000; ++i) {
        lock_guard<mutex> lock(mtx);
        ++counter;
        cout << thread << " " << counter << endl;
    }
}

int main() {
    thread t1(increment, "thread 1:");
    thread t2(increment, "thread 2:");

    t1.join();
    t2.join();

    cout << "Final count: " << counter << endl;
    return 0;
}