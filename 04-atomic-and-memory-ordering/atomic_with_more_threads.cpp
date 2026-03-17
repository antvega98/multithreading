#include <iostream>
#include <thread>
#include <atomic>
#include <vector>

using namespace std;

atomic<int> counter(0);

void increment() {
    for(int i = 0; i < 1000; ++i) {
        counter++;
    }
}

int main() {
    vector<thread> threads;
    for(int i = 0; i < 100; ++i) {
        threads.emplace_back(increment);
        /*
            emplace_back(increment) is a better way than doing:
                >threads.emplace_back(thread(increment))
                OR
                >thread temp(increment);
                >threads.emplace_back(move(increment)); // move (or 'transferring' ownership) would be required.
                * it cannot be copied i.e threads.emplace_back(temp);
            A temp object would not be created, instead it constructs the thread directly inside the vector.
        */
    }

    for(auto& t: threads) {
        t.join();
    }
    cout << "Final counter: " << counter << endl; 
    return 0;
}