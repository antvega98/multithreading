#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex coutMutex;

/*
    Mutex: mutual exclusion. This guarantees only one thread access a critical part one at a time.
    In this case "cout" in print method.
*/

void print(string message) {
    lock_guard<mutex> lock(coutMutex);
    cout << message << endl;
}

int main() {
    thread t1(print, "1st thread.");
    thread t2(print, "2nd thread.");
    thread t3(print, "3rd thread.");

    t1.join();
    t2.join();
    t3.join();
    return 0;
}