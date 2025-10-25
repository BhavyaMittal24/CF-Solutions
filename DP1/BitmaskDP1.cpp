#include<bits/stdc++.h>
using namespace std;

int countSetBits(int n){
    int cnt = 0;
    while(n > 0){
        if(n % 2 == 1) cnt ++;
        n = n/2;
    }
    return cnt;
}
int main(){
    
    int n;
    cin >> n;

    // dp[bitmask] : no of ways to arrange the rem numbers in the mask to form a total length of n for the sequence
    // set bits represent the no of bits already used up. 

    // dp[000] = dp[001] + dp[010] + dp[100] -> [1  , [2,  [3, ]
    // dp[001] = dp[011] + dp[101]  [1,2  , [1,3
    // dp[010] = dp[011] + dp[110]  [2,1] , [2,3 

    // dp[111] = 1 : no of ways to form when all n bits are selected

    int maskSize = 1 << n;

    vector<int> dp(maskSize,0);
    dp[maskSize-1] = 1;


    // dp[mask] = dp[mask | (1 << k)] where k is bw 0 to n-1 : new Mask > mask
    for(int mask = maskSize-2; mask >= 0; mask --){
        long long cnt = 0;
        for(int k=0;k<n;k++){

            // ( mask & (1 << i) ) == 0
            if(  (mask & (1 << k)) == 0){
                int nextMask = mask | (1 << k);
                cnt += dp[nextMask];
            }
        }
        dp[mask] = cnt;
    }

    cout << dp[0] << endl;
    return 0;
}