#include<bits/stdc++.h>
using namespace std;

long long minTime(int idx, vector<int> & arr, vector<int> & keys, set<int>& usedKeys, int p){

    if(idx == arr.size()){
        // find them min time to make all people from i to n-1 : n to n-1 = 0;
        return 0;
    }

    long long minimumTime = 5e9;

    for(int j = 0; j < keys.size(); j ++){

        if( usedKeys.count(keys[j]) == 1 ){
            // already used up ky
            continue;
        }

        long long timeTaken = abs(arr[idx] - keys[j]) + abs(keys[j] - p);
        
        usedKeys.insert(keys[j]);

        // ith index : all possible j
        // min time across all j 
        // across all subproblems maximum time 
        //i ,i+1, ... maximum time between all of them 
        long long nextTime = minTime(idx +1, arr, keys, usedKeys, p);

        if( nextTime != 5e9){
            minimumTime = min( max(timeTaken, nextTime), minimumTime);
        }
        usedKeys.erase(keys[j]);
    }

    return minimumTime;
}
int main(){

    int n, k, p;
    cin >> n >> k >> p;

    // n people , k keys and p is the final stop

    vector<int> arr(n);
    vector<int> keys(k);
    for(int i = 0; i < n; i ++) cin >> arr[i];

    for(int i = 0; i < k; i ++) cin >> keys[i];

    // Find the minimim time  taken to go and collect the keys and meet at office

    // set<int> usedKeys;
    // int ans = minTime(0, arr, keys, usedKeys, p);
    // cout << ans << "\n";

    sort(arr.begin(), arr.end());
    sort(keys.begin(), keys.end());

    vector<vector<int>> dp( n+1, vector<int> (k+1, INT_MAX));

    // dp[i][j] : min time taken to make all people from suffix i to n-1 reach the office where ith person is trying to take the jthi key
    
    // dp[i+1][j] or dp[i][j+1]

    // dp[n][anythin] = 0;

    // dp[anything][k] = INF because if we dont habe ay keys it will take infinite time not possib;e to reach the office
    for(int i = 0; i <= k; i++){
        dp[n][i] = 0;
    }

    // dp[0][0]

    for(int i = n-1 ; i >= 0; i --){
        for(int j = k -1 ; j >= 0 ; j--){

            int cost = abs(arr[i] - keys[j]) + abs(keys[j] - p);
            // takr the jth key : ans will be i+1 to n-1 where you can only pick the j+1th key onwards
            dp[i][j] = max(cost, dp[i+1][j+1]);

            dp[i][j] = min( dp[i][j], dp[i][j+1]);
        }
    }

    cout << dp[0][0] << "\n";
    return 0;
}