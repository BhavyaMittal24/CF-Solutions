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

const long long mod = 1e9+7;
// int maxN = 1e6+1;
// vector<int> dp(maxN,-1);

long long sum(long long x, vector<int> &coins, vector<long long> &dp){
   if(x <0) return 0;
   if(x==0) return 1;
   
   if(dp[x] != -1) return dp[x];
    
   long long ways = 0;
   for(int i=0;i<coins.size();i++){
    if(x >= coins[i]) ways = ways % mod + sum(x-coins[i],coins,dp) % mod;
    else break;
   }
   return dp[x] = ways % mod;
}

int main(){
   long long n;
   long long  x;
   cin >> n >> x;
   vector<int> coins(n);
   vector<long long> dp(x+1,-1);
   for(int i=0;i<n;i++) cin >> coins[i];
   sort(coins.begin(), coins.end());
   long long ways = sum(x,coins,dp);
   cout << ways << endl;
   return 0;

}