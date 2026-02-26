#include <iostream>
#include <thread>

using namespace std;

/*
    This is a race condition. Since counter is not protected, both threads may read and write it at the same time. 
    You may have this:
        counter = 10
        thread 1 reads 10
        thread 2 reads 10
        thread 1 writes 11
        thread 2 writes 11
    
    Run this multiple times, you will get different outputs.
*/

int counter = 0;

void increment() {
    for(int i = 0; i < 1000; ++i) {
        ++counter;
    }
}

int main() {
    thread t1(increment);
    thread t2(increment);

    t1.join();
    t2.join();
    cout << counter << endl;
    return 0;
}