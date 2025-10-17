// //Minimizing coin change problem

// // iterative dp _> faster, cleaner, no time for stack and pop and push
// // evaluates all states : Subproblem is solved inly once no need for recursion always


// For example, if the coins are \{1,5,7\} and the desired sum is 11, an optimal solution is 5+5+1 which requires 3 coins.


// 1  <= n <= 100
// 1  <= x <= 10^6
// 1  <= ci  <= 10^6

// Any dp problem : Break, divide conquer
// state
// transition equation
// base case
// final answer

// 11, {1,5,7}

// 11 : 1+1+..

// 11 = 1+1+1+1+7

// dp[x] : min number of coins used to get the target sum

// dp[0] = 0 : (No coin is selected) : Number of coins used to get 0 is 0 coins 

// dp[-ve] : invalid state : I can't get this value impossible number of coins to make target sum -ve : 1e9

// if x >= ci, dp[x] = 1+min(dp[x-ci])

// final answer = dp[x]

#include <bits/stdc++.h>
using namespace std;

int main(){

  int n;
  int x;
  cin >> n >> x;
  vector<int> c(n);
  for(int i=0;i<n;i++) cin >> c[i];
  vector<int> dp(x+1,1e9);

  // number of coins used to get the sum 0  = 0 
  dp[0] = 0;
  for(int i=1;i<=x;i++){
     int target = i;
     int minWays = 1e9;
     for(int j=0;j<c.size();j++){
       if(target >= c[j]) {
          minWays = min(minWays, dp[target-c[j]]);
       }
     }
     if(minWays == 1e9) dp[i] = 1e9;
     else dp[i] = 1 + minWays;
  }

  if(dp[x] == 1e9) dp[x] = -1;
  cout << dp[x] << endl;
  return 0;
}
