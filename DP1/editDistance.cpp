// // Edit Distance

// // n,m <= 5000

// // string s1 (n)
// // string s2 (m)

// dp[i][j] = min operations used to make string s1 from i to n-1 and string s2 from j to m-1 equal

// dp[n][j] = m-j;

// dp[i][m] = n-i

// // string from end of s1 and end of s2 to 
// dp[n][m] = 0
// we can insert
//         remove
//         replace

//  LOVE
// MOVIE
    
//                0,0
 
// insert          delete          replace
// M (i,j+1)       i+1,j           i+1,j+1


// dp[i][j] =  1+min(dp[i+1][j], dp[i][j+1], dp[i+1][j+1])

// #include<bits/stdc++.h>
// using namespace std;


// 0   1 2 3   m-2 m-1
// 1
// 2

// n-2           i,j     i,j+1
// n-1           i+1,j   i+1,j+1

#include <bits/stdc++.h>
using namespace std;

int main(){

  string s1;
  string s2;
  cin >> s1;
  cin >> s2;
  int n = s1.length();
  int m = s2.length();

  vector<vector<int>> dp(n+1, vector<int>(m+1,1e9));
  for(int i=0;i<n;i++) dp[i][m] = n-i;
  for(int j=0;j<m;j++) dp[n][j] = m-j;
  dp[n][m] = 0;
  
  for(int i = n-1;i>=0;i--){
     
     for(int j=m-1;j>=0;j--){
        if(s1[i] == s2[j]){
           dp[i][j] = dp[i+1][j+1];
           continue;
        }
        dp[i][j] = 1 + min(dp[i+1][j], min(dp[i][j+1], dp[i+1][j+1]));
     }
  }

  cout << dp[0][0] << endl;
  
  return 0;
}