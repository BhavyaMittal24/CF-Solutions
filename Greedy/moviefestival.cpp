#include<bits/stdc++.h>
using namespace std;


// sprt events based on thier time

bool compare(pair<int,int> &a, pair<int,int> &b){

    if(a.first < b.first) {
        return true;
    }

    else if(a.first > b.first) {
        return false;
    }

    else {
        // same time then have exit one sorted first event marking the end
        return a.second < b.second;
        // -1 < +1
    }
}
int main(){

    int n, k;
    cin >> n >> k;

    // max movies i can watch using k people
    // if intersecting movies : i need to use 2 people to watch them
    // if non intersecting : i can watch them on my own
    
    
    // : max no of moves only one prson can watch : basically can watch one at one time : max no of non overlappign intervals out of n 
    // based on endtime : pick up

    // total number of people required to be able to watch all the movies : basically max no of overlapping intervals at one given time
    

    // no of moves i will miss at one time : max no of movies i will miss : (no of movies i have in the theatre at one ppint of time - k) : max value for this
    
    
    // ans = n - max no of movies i will miss


    // sort movie end before movie start 

    vector<pair<int,int>> intervals(n);

    vector<pair<int,int>> events;
    // start , +1
    // end -1;
    // if same time start and end
    // [1,4] [4,5]
    // +1, -1, +1, -1

    for(int i  = 0; i < n; i ++){
        int a, b;
        cin >> a >> b;
        // a = start
        // b - endtime
        intervals[i] = {a,b};
        events.push_back({a,+1});
        events.push_back({b,-1});
    }

    sort(events.begin(), events.end(), compare);

    int currMovies = 0;

    int miss = 0;

    int maxMiss = 0;
    for(auto event : events){

        currMovies += event.second;

        miss = max(0, currMovies - k);
        maxMiss = max(maxMiss, miss);
    }

    cout << n - maxMiss << endl;
    return 0;
}