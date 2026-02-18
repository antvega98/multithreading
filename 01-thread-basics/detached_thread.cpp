#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void worker() {
    cout << "Worker thread started." << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Worker thread finished." << endl;
}

int main() {
    thread t(worker);
    t.detach();
    cout << "Main thread continues..." << endl;

    // Putting main thread to sleep to allow worker thread to finish. 
    // If set to less time, main will exit and destroy worker thread.
    this_thread::sleep_for(chrono::seconds(3));

    cout << "Main thread exiting..." << endl;
    return 0;
}