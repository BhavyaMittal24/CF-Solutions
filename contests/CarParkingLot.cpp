#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int addNumbers(int a, int b) {
    return a+b;
}


// Your old code in python3 has been preserved below.
// def addNumbers(a,b):
//     sum = a + b
//     return sum

// num1 = int(input())
// num2 = int(input())

// print("The sum is", addNumbers(num1, num2))

// Design a multi floor Advanced car parking system , that tells the user nearest available parking spot. 
//     a. Write the various use cases ( Functional & Non Functional requirements ) first in detail. 
//     b. Write all the classes and the data structures, members required. 
//     c. Try to implement the method to find the nearest parking spot. 
//     d. Assume one entry and exit. 

// Classes for each object

// Vehicle

class Vehicle {
  
    
    public : 
    string userId;
    string ownerName;
    string type;
    Vehicle(string userId, string ownerName, string type ){
        this->ownerName = ownerName;
        this->userId = userId;
        this->type = type;
    }
};



class ParkingSpot{
    public :
    string spotId;
    int floorNumber;
    int distanceFromEntry;
    bool isAvailable;
    
    public : 
        ParkingSpot( string id, int floor, int distance){
            this->spotId = id;
            this->floorNumber = floor;
            this->distanceFromEntry = distance;
            this->isAvailable = true;
        }
        // occupy the parking spot
        void occupy(){
            this->isAvailable = false;
        }
        
        int getFloor(){
            return this->floorNumber;
        }
        
        int getDistance(){
            return this->distanceFromEntry;
        }
        // free the parkign spot
        void free(){
            this->isAvailable = true;
        }
};


class SpotComparator {
    bool operator() ( ParkingSpot* a, ParkingSpot* b){
        if(a->getFloor() == b->getFloor()){
            return (a->getDistance() > b->getDistance());
        }
        
        return a->getFloor() > b->getFloor();
    }
};

class ParkingLot {
    public :
    int totalFloors;
    int spotsPerFloor;
    // vector of parking lots
    // _ _ _ _ floor 1 
    // _ _ _ _  flooe 2
    vector<vector<ParkingSpot>> allSpots;
    // sort these parking spots based on their availability and their min distance from the entry
    
    // ds that can give me min value 0(1)
    // // min at starting in a mao : inset /delete/search 0(logk)
    priority_queue<ParkingSpot*, vector<ParkingSpot*>,SpotComparator> availableSpots;
    
    // reg of car -> parking spot
    unordered_map<string, ParkingSpot*> parkedVehicles;
      
    ParkingLot(int floors, int spotsPerFloor){
        totalFloors = floors;
        this->spotsPerFloor = spotsPerFloor;
        
        for(int f=1;f<=totalFloors;f++){
            vector<ParkingSpot> floorSpots;
            for(int s =f;s<= spotsPerFloor;s++){
                string id = "F" + to_string(f) + "S" + to_string(s);
                floorSpots.emplace_back(id,f,s);
            }
            allSpots.push_back(floorSpots);
        }
      
    // add pointer of all spots to the pq
    
        for(auto &floor : allSpots){
            for(auto &spot : floor){
                this->availableSpots.push(&spot);
            }
        }
    }
   

    void parkVehicles(const Vehicle &vehicle){
        if( availableSpots.empty()){
            cout << "No avaialbe space for your" << vehicle.userId << endl;
            return;
        }
        
        ParkingSpot * spot = availableSpots.top();
        availableSpots.pop();
        spot->occupy();
        
        // msp of vrhicle id to spot pointer reference
        parkedVehicles[vehicle.userId] = spot;
        
        cout << "vehicle " << vehicle.userId << " parked at " << spot->spotId<< "  flor " << spot->getFloor();  
    }
    
    void removeVehicles(string userid){
        if(parkedVehicles.find(userid)  == parkedVehicles.end()){
            cout << "not found vehicle with id" << userid ;
            return;
        }
        
        ParkingSpot* spot = parkedVehicles[userid];
        spot->free();
        availableSpots.push(spot);
        parkedVehicles.erase(userid);
        cout << "vehicle" << userid << " left , spot " << spot->spotId << "is now free" << endl;
    }
    
    
    void printStatus(){
        cout << "Avaialable Spots" << this->availableSpots.size() << endl;
        cout << "parke vehicles " << this->parkedVehicles.size() << endl;
    }
};


int main(){
    
    // 3 floors, 
    // 5 spots per floor
    ParkingLot lot(3,5);
    Vehicle v1 ("123", "bhavya","bike");
    Vehicle v2("234", "Saurabh","car");
    
    lot.parkVehicles(v1);
    lot.parkVehicles(v2);
    lot.printStatus();
    
    lot.removeVehicles("123");
    
    
    return 0;
}

