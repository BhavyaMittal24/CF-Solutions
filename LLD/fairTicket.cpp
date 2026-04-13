#include<bits/stdc++.h>
using namespace std;


/*
 a fair task manager where tasks have some severity, low, med and high
 the tasks are executed in the order of high, med and then low. But there is a catch, if there is some task
 which is of low type and there for more than 5 seconds, then it will be moved to High priority so it does not starve.
*/

enum class Severity {
    LOW,
    MED,
    HIGH
};

class Task {

    int taskId;
    Severity sev;
    TimePoint arrivalTime;

    public :

    int getTaskId(){
        return taskId;
    }

    Severity getSeverity(){
        return sev;
    }

    TimePoint getArrivalTime(){
        return arrivalTime;
    }
};

class TaskManager{

    public: 

    queue<Task*> high;
    queue<Task*> med;
    queue<Task*> low;

    // a mutex lock to guard the shared resources which are shared resources : common 

    void insert(Task* task){

        if(task->getSeverity()  == Severity ::HIGH){
            high.push(task);
        }
        else if(task->getSeverity() == Severity ::MED){
            high.push(task);
        }

        else {
            low.push(task);
        }
    }

    Task* getNextTask(){

        Task* nextTask = nullptr;

        if( !high.empty() ){
            nextTask = high.front();
            high.pop();
        }
        else if( !med.empty()){
            nextTask = med.front();
            med.pop();
        }

        else if(! low.empty()){
            nextTask = low.front();
            low.pop();
        }
        return nextTask;
    
    }

    void moveLowFromHigh(){

        // move expired Tasks from low to high queue
        // 3 4 5 6 8 9  : currTIme = 10

        Timepoint currTime = clock:: now();

        while(!low.empty() && currTime - low.front()->getArrivalTime() > 5){

            Task* lowTask = low.front();
            low.pop();
            high.push(lowTask);
        }
    }

    
    void worker(){

    }

};