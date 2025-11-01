#include<bits/stdc++.h>
using namespace std;

//int dp[5001][5001];
long long minTime(int i, int p, vector<int> &arr, vector<int> &hot, vector<int> &cold){
    int n = arr.size();
    if(i == n){
        return 0;
    }

    long long time1 = 0;
    if(i>= 1 && arr[i-1]== arr[i]) time1 = hot[arr[i]-1];
    else time1 = cold[arr[i]-1];

    time1 += minTime(i+1, p,arr, hot, cold);


    long long time2 = 0;
    if(p == arr[i]) time2 = hot[arr[i]-1];
    else time2 = cold[arr[i]-1];

    time2 += minTime(i+1, arr[i-1],arr, hot, cold);
    return min(time1, time2);
}

void solve(){
    int n;
    int k;
    cin >> n >> k;
    // memset(dp,-1,sizeof(dp));
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];

    // arr[i] : arr 1 to arrn 
    vector<int> cold(k), hot(k);


    // o to k-1
    //  1 <=ai <=k 
    // ai stored in i-1
    //time for type i is stored at i-1
    for(int i=0;i<k;i++) cin >> cold[i];
    for(int i=0;i<k;i++) cin >> hot[i];


    // long long ans = minTime(0,0,arr, hot,cold);

    // cout << ans << endl;

    // // n * k
    vector<vector<long long>> dp(n+1,vector<long long>(k+1,0));

    
    // dp[i][col] : min time to perfom programs from i to n-1 such that at ith program ; 
    // ai-1 is at top and x
    for(int i=n-1;i>=0;i--){
        for(int x = 0;x<=k;x++){
            // place at ai-1
            long long sameChoice = 0;
            if(i>=0 && arr[i] == arr[i-1]) sameChoice = hot[arr[i]-1];
            else sameChoice = cold[arr[i]-1];
            sameChoice = sameChoice + dp[i+1][x];

            long long diffChoice = 0;
            if(arr[i] == x) diffChoice= hot[arr[i]-1];
            else diffChoice = cold[arr[i]-1];
            if(i>=1) diffChoice = diffChoice + dp[i+1][arr[i-1]];
            else diffChoice = diffChoice + dp[i+1][0];

            dp[i][x] = min(sameChoice, diffChoice);
        }
    }
    cout << dp[0][0] << endl;

}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}