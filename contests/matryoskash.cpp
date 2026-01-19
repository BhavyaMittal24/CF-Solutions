// 1 ,1,1 1
// 2,2,2,2
// 3,3,3

// 4,4

// 6,6

// 8,8

// in one contigous sequcne of keys, kind the max frequecy of key

// if not contigous, +freq[key]

#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    cin >> n;

    map<int,int> mp;
    for(int i = 0; i < n; i ++){
        int x;
        cin >> x;
        // mp[number] -> frequency of the number
        mp[x]++;
    }

    auto it = mp.begin();

    // 1 2 3 4 6
    int minDolls = 0;
    int rangeAns = 0;

    rangeAns = it->second;
    int prevFreq = it->second;
    int currFreq = 0;

    auto prev = mp.begin();
    it++;

    while(it != mp.end()){
        
        currFreq = it->second;

        int currKey = it->first;
        int prevKey = prev->first;
        if( currKey != ( prevKey + 1)){
            minDolls += rangeAns;
            rangeAns = currFreq;
        }

        else {
            if(prevFreq < currFreq){
                rangeAns += (currFreq - prevFreq);
            }
        }
        prevFreq = currFreq;
        it++;
        prev++;
    }

    minDolls += rangeAns;

    cout << minDolls << "\n";
    return;
}

// 2 2 3 4 4

// 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while(t--){
        solve();
    }
    return 0;
}