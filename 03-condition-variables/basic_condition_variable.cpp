#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

/*
    3 Pieces Required of Condition Variables:
        - Mutex: protects shared data.
        - Condition Variable: used to sleep and wake threads.
        - Shared condition: Thing we wait for.
*/

mutex mtx;
condition_variable cv;
bool ready = false;

void worker() {
    unique_lock<mutex> lock(mtx);
    cout << "Worker is waiting..." << endl;
    cv.wait(lock, [] { return ready; });
    cout << "Worker: Received signal." << endl;
}

int main() {
    thread t(worker);
    this_thread::sleep_for(chrono::seconds(3));

    {
        lock_guard<mutex> lock(mtx);
        ready = true;
        cout << "Main: ready = true." << endl;
    }

    cv.notify_one();
    t.join(); // t.join() is at the end. Tells main to wait for t to finish.
    return 0;
}

