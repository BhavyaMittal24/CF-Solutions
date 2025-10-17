// coin change

// sum = 9
// coins = {2,3,5}

// number of ways I can form the sum using the coins.


// I can use the same coin a repeated no of times

// // if the order of the coins chosen is different, then it's a diff way

// 2+2+5
// 2+5+2
// 5+2+2
// 3+3+3
// 2+2+2+3
// 2+2+3+2
// 2+3+2+2
// 3+2+2+2


// 9 = 2 + (7)
//     3 + (6)

//-1 : 0
//x = 0 : ways = 1, don't choose any coin

#include <bits/stdc++.h>
using namespace std;

// TC : // number of sub probelsm : x
// TIme for eacg function call/ ubsproblem : o(n)
// overall TC : o(n*x)

//If the coins are \{1,5,7\} and the desired sum is 11, an optimal solution is 5+5+1 which requires 3 coins.
const long long mod = 1e9+7;
// int maxN = 1e6+1;
// vector<int> dp(maxN,-1);

long long minCoins(long long x, vector<int> &coins, vector<long long> &dp){
   if(x <0) return LONG_LONG_MAX;
   if(x==0) return 0;
   
   if(dp[x] != -1) return dp[x];
    
   long long ways = LONG_LONG_MAX;
   for(int i=0;i<coins.size();i++) ways = min(ways, minCoins(x-coins[i],coins,dp)) % mod;
   if(ways == LONG_LONG_MAX) return dp[x] = ways;
   return dp[x] = (ways +1)% mod;
}

int main(){
   long long n;
   long long  x;
   cin >> n >> x;
   vector<int> coins(n);
   vector<long long> dp(x+1,-1);
   for(int i=0;i<n;i++) cin >> coins[i];
   sort(coins.begin(), coins.end());
   long long ways = minCoins(x,coins,dp);
    if(ways == LONG_LONG_MAX) cout << -1 << endl;
    else
   cout << ways << endl;
   return 0;

}