//Grid paths 1
#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9+7;

// dp[i][j] = number of ways to go from state (i,j) to (n-1,n-1); 

vector<vector<long>> dp(1001, vector<long> (1001,-1));


long long findWays(int i, int j, vector<string> &patterns){
   int n = patterns.size();
   int m = patterns[i].size();
   if(i>=n || j>=m) return 0;
   if(i == n-1 && j == m-1 && patterns[i][j] != '*') return 1;
   if(patterns[i][j] == '*') return 0;
   
   if(dp[i][j] != -1) return dp[i][j];  
   
   // Go Down or GO right only : Each ways is independent of other but OR. TO complete the task
   // No of ways to reach i,j
   long long ways = (findWays(i+1,j,patterns) % mod + findWays(i,j+1,patterns) % mod) % mod;
   return dp[i][j] = ways;
}
int main(){

  int n;
  cin >> n;
  vector<string> pattern(n);
    for(int i=0;i<n;i++){
        cin >> pattern[i];
    }
  long long ways = findWays(0,0,pattern);
  cout << ways << endl;
  return 0;

}