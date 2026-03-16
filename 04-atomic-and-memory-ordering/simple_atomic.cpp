#include <iostream>
#include <atomic>
#include <thread>

using namespace std;

/* 
    An atomic variable guarentees each operation happens as one indivisible step - no other thread can observe it halfway.
    
    Atomics vs Mutexes:
        - Atomics: lock-free, fast, for simple variables.
        - Mutexes: blocking (puts threads to sleep), heavier.
*/

atomic<int> counter(0);

void increment() {
    for(int i = 0; i < 1000; ++i) {
        counter++;
    }
}

int main() {
    thread t1(increment);
    thread t2(increment);

    t1.join();
    t2.join();

    cout << "Final count: " << counter << endl;
    return 0;
}