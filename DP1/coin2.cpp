// coin combinations 2


// number of ways to make a target from a given set of coins

#include<bits/stdc++.h>
using namespace std;

int main(){

  int n,x;
  cin >> n >> x;
  
  vector<int> coins(n);
  for(int i=0;i<n;i++) cin >> coins[i];


  const long long mod = 1e9 + 7;
  //vector<vector<long long>> dp(n+1, vector<long long>(x,0));
 

  vector<long long> prev(x+1,0);
    vector<long long> curr(x+1,0);
  // dp[i][j]  : no of distinc ways, subsets/ subsequences of coins used to make a target sum j from all elements in array from i to n-1
 
  // target = 9
  //  2 3 5

  //     9,0 
  //    
  // dp[i][j] = dp[i][j - arr[i]] + dp[i+1][j]
  
  // base case : dp[anything][0] = 1 : no of ways to make sum as 0 is just 1 : {} :empty subset/subsequence

  // dp[n][anything except 0] : no of ways to make some target from an array containign no element = 0;

  // final anser = dp[0][target]
//  for(int i=0;i<=n;i++){
//    dp[i][0] = 1;
//  }  

 prev[0] = 1;
  
 //for(int i=1;i<=x;i++) prev[i] = 0;

 for(int i =n-1;i>=0;i--){
   
    curr[0] = 1;
   for(int j=1;j<=x;j++){
       
       // dp[i][j]
       long long skip = 0;
       long long pick = 0;
       
       skip = prev[j];
       if(j >= coins[i]){
          pick = curr[j-coins[i]];
       }
       curr[j] = (pick + skip) % mod;
   }
   prev = curr;
 }
 
  cout << curr[x] << endl;
 
  return 0;
}