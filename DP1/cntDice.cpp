#include <bits/stdc++.h>
using namespace std;

long long mod = 1e9+7;

long long getWays(long long sum, vector<long long> &dp){
 if(sum == 0) return 1;
 if (sum < 0) return 0;
 
 if(dp[sum] != -1) return dp[sum];
 
 long long ways = 0;

 for(int i=1;i<=6;i++){
    ways = ways % mod + getWays(sum-i, dp) % mod;
 }
  return dp[sum] = ways;
}

int main(){
    int n;
    cin >> n;
    vector<long long> dp(n+1,-1);
    long long sum = getWays(n,dp);
    cout << sum % mod << endl;
    return 0;
}