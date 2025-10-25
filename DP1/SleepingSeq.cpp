#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,h,l,r;
    // no of sleeping times between 0 and n-1
    cin >> n >> h >> l >> r;

    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];

    // curr time = 0 ---ao time waits > ao
    //                                  a0-1 time when he can sleep again 
    // waits for ai or ai-1 before he can go to sleep for ith time

    // sleeps from 0 to to n-1th time

    // dp[i][currentTime] : represent the max no of sleeping times which are good [currentTime is between [l,r]] when the user wants
    // to sleep from [i .. n-1] times. 
    vector<vector<long long>> dp(n+1, vector<long long>(h+1,0));

    //dp[n][anythinhg] = 0'
    // for(int i=n-1;i>=0;i--){
    //     for(int currTime=0; currTime <=h;currTime++){
    //         long long newTimeFull = (currTime + arr[i]) % h ;
    //         long long newTimeFullMinus1 = (currTime + arr[i] -1) % h;
    //         long long cntGoodTimesWhenFullWait = (newTimeFull <= r && newTimeFull >=l) ? 1 : 0 ;
    //         long long cntGoodTimesWhenFullMinus1Wait = (newTimeFullMinus1 <= r && newTimeFullMinus1 >= l) ? 1 : 0;

    //         dp[i][currTime] = max(cntGoodTimesWhenFullWait+ dp[i+1][newTimeFull], cntGoodTimesWhenFullMinus1Wait + dp[i+1][newTimeFullMinus1]);
    //     }
    // }

    // dp[i][currTime] : max good sleeping times when he decides to sleep from i to n-1 times optimally
    //cout << dp[0][0] << endl;

    // dp[0][anything] = 0;
    for(int i=1;i<=h;i++){
        dp[0][i] = -1e8;
    }

     for(int i=1; i<=n;i++){
        for(int currTime=0; currTime <=h;currTime++){
            
            int cnt = ( currTime >= l && currTime <= r) ? 1 : 0;

            long long newTimeFull = (currTime - arr[i-1] + h) % h;
            long long newTimeMinus = (currTime - arr[i-1] + 1 + h) % h;
            dp[i][currTime] = cnt + max(dp[i-1][newTimeFull], dp[i-1][newTimeMinus]);
        }
    }

    long long maxTimes = 0;
    for(int i=0;i<=h;i++){
        maxTimes = max(dp[n][i], maxTimes);
    }

    cout << maxTimes << endl;
    return 0;

    // max(n,anythinh)
    
    // a0 a1 a2 .... an-1
     //                  0th time           1st
    // 0 --        > a0-1 / a0            a1-1/a1
    // 0                                              i
    //                    i-1th time            ith time, currentTime
    //                                              
    // woke up         waits this long and then goes to sleep at time currTime + ai-1/ai for the ith time

    // dp[i][j] : max no of good sleeos when is sleeping for the ith time at the time j
    //         i-1th sleep                ith sleep
    //           j - a[i]                  j is the currTime
}   //           j - (a[i]-1)
// dp[i][j] = 1 /0 + max(dp[i-1][j - a[i]], dp[i-1][j - a[i]] + 1);