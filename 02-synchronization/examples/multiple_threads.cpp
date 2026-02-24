#include <iostream>
#include <thread>

using namespace std;
/* 
    Following example shows multiple threads calling a method. But cout is not thread safe.
    Cout is a shared global object. When multiple threads write to it at the same time,  
    output is unpredictable, lines can interleave, and in rare cases cane be corrupted.
*/
void print(string message) {
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