#include <iostream>
#include <thread>

using namespace std;

void print(int threadNum) {
    cout << threadNum << endl;
}

int main(){
    thread t1(print, 1);
    t1.join();

    return 0;
}