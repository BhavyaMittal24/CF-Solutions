#include<bits/stdc++.h>
using namespace std;

// sort basis of start time
// dont use equal sign here : this may guve tle : esy tp check based on simple > or less 
bool compare(vector<int> & a, vector<int> & b){
    if(a[1] < b[1] ) return true;

    else if(a[1] > b[1]) return false;

    else {
        return a[2] < b[2];
    }
}

int main(){
    

    /*

    1 3
    4 6
    3 6

    find the total number of rooms : no of overlapping intervals
    // customer number 0 : {start0, end0}
                        1 : {start1, end1}
                        2 : {start2, end2}

    sort based on start time

    a continous subarray where all intervals are overlapping with each other, that is the number of rooms i would need.
    n^2 solutiom according to me


    n = no of intervals in the maximum overlapping interval

    sa, ea      sb, eb
    // to overlap : sa >= sb || ea >= sb : we are overallpping only then 



    Greedy strategy : 

    rooms 
    set of avaialbe rooms and set of occupied rooms

    process guests in order

    if no room available <= check in time for the guest, create a new room
    if a room available, give him that room
    */

    int n;

    cin >> n;

    vector<vector<int>> guests(n+1);

    for(int i = 1; i <= n; i ++){
        int s, e;
        cin >> s >> e;

        guests[i] = {i, s, e};
    }

    vector<int> allocation(n+1,-1); 
    // guest 0 : room number : allocation[i];
    // guest i -> allocation[i]

    sort(guests.begin()+1, guests.end(), compare);

    // pq for { earlestAvailableTime , roomNumber }

    // min heap

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

    
    int cnt = 0;

    for(int i = 1; i <= n; i++){


        int startTime = guests[i][1];
        int guestNumber = guests[i][0];
        int endTime = guests[i][2];

        //cout << startTime <<  " " << endTime << " " << guestNumber << endl;
        if( pq.empty() ) {
            cnt++;
            allocation[guestNumber] = cnt;
        }

        else {
            int mostRecentAvailableTime = pq.top().first;

            if( mostRecentAvailableTime <= startTime){
                allocation[guestNumber] = pq.top().second;
                pq.pop();
            }
            // no room avaialble
            else {
                cnt++;
                allocation[guestNumber] = cnt;
            }
        }

        pq.push({endTime + 1, allocation[guestNumber]});
    }

    cout << cnt << endl;

    for(int i = 1; i <= n; i ++){
        cout << allocation[i] << " ";
    }
    cout << endl;;

    return 0;
}