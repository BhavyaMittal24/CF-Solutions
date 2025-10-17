// Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to calculate the number of distinct ordered ways you can produce a money sum x using the available coins.
// For example, if the coins are \{2,3,5\} and the desired sum is 9, there are 3 ways:

// 2+2+5
// 3+3+3
// 2+2+2+3


// // distinct ways

// sorted coins : 2, 3, 5
// target = 9

// 2 + 2 + 5

// 2 + 2 + 2 + 3
// 3 + 3 + 3

// distinct ways

// f(current coin, target ) : distinct ways to get to the target when you have preselected the current coin


// // find first index having value >= coins[coinIndex] : nextIndex

// dp[coinIndex][target] = dp[netxIndex][target - coins[nextIndex]] + …


// dp[][0] : 1 : 1 way when the ntarget sum is 1

// 0 coinIndex means no coin is selected
// 1 : 1st cooin

// n : nth coin
// dp[n][] : 0 : 0 ways to get to target when selected coin is n 

// if(target is -ve) 0 ways

// final ans : dp[0][target]

// dp[i][j] : no of distinct ways to get to target sum when the first coin we can choose has value > coins[i]

// 3 4 5 6 7
// find j such that a[j] > a[prevIndex]

#include <bits/stdc++.h>
using namespace std;

// int findFirstIndex(int prevIndex, vector<int> &coins){
//   if(prevIndex == 0) return 1;
//   int low = 0;
//   int high = n;
//   int mid = 0;
//   int ans = -1;
//   while(low <= high){
//     mid = (low +high)/2;
//     if( coins[mid] > a[prevIndex]){
//         ans = mid;
//         high = mid-1;
//     }
//     else {
//         low = mid+1;
//     }
//   }
//   return ans;
// }


int main(){

    int n;
    int target;
    cin >> n >> target;
    vector<int> coins(n);
    for(int i=0;i<n;i++) cin >> coins[i];
    vector<vector<int>> dp(n+1, vector<int>(target+1,0));

// no of distinct ways to make sum = 0 is 1
for(int i=0;i<=n;i++) dp[i][0] = 1;
for(int i=1;i<=target;i++) dp[n][i] = 0;
    
sort(coins.begin(), coins.end());

for(int i=n-1;i>=0;i--){
   if(target % coins[i] == 0) dp[i][target] = 1;
   for(int j=i+1; j<n;j++){

      if(target >= coins[j])
      {
       dp[i][target] += dp[j][target - coins[j]];
      }
   }
}

cout << dp[0][target] << endl;
return 0;
}
// dp[i][j] : distinct ways to produce trget when the current index is i and sum is j





