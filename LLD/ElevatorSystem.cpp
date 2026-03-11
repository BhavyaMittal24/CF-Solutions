#include<bits/stdc++.h>
using namespace std;


/*
Design a Elevator system


Clarify and scope requirements

One elevator : multiple 

concurrency : many people can request the same elevator : multiple elevators are there 
min wait time should be there

capacity constraint ?? 

all these are taken care of btw T M A C oncurency


Core APIs and key input output : 3 - 6 apis in scope


-requestLiftExternal(floorNo, direction)

pressed from inside

-moveToFloor(desiredFloor, vector<Elevator*>)

-addElevator(Elevator* )



ER Model/ Data model and persistence

ElevatorState
-IDLE
-MOVING_UP
-MOVING_DOWN


Elevator
-int floor
-ElevatorState state
-int maxCapacity
-currCapacity



ElevatorService
- vector<Elevator*> // storing ref to all the elevators

// Iplement a strategy pattern to choose whoch algirthm to get the lift for a user
// 
core APIS


UML COre class and design



Design patterns

*/