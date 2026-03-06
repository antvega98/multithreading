#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

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

    t.join();
    return 0;
}

