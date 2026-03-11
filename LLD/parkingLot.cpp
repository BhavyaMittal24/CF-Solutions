// #ifndef _GLIBCXX_HAS_GTHREADS
// #define _GLIBCXX_HAS_GTHREADS
// #endif
#include "mingw.thread.h"
#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

using Clock = std::chrono::system_clock;
using TimePoint = std::chrono::time_point<Clock>;








/*



*/






class Ticket{

    int id;
    string licensePlate;
    int spotId;

    TimePoint startTime;
    TimePoint endTime;
    double price;
};


void increment(int x){

    for(int i = 0; i < 5; i ++){
        x ++;
    }
}
int main(){


    // try implementing a lock guard and how it works

    int x = 5;


    thread t1(increment, x);

    thread t2(increment, x);

    std::lock_guard<std::mutex> lock(mtx); // oly valid in the scope: As soon as it goes out of scope, it gets deleted
    t1.join();
    t2.join();


    // waits for here : main exectuion resumes from jere

    cout << "Value is " << x << "\n";
    return 0;
}