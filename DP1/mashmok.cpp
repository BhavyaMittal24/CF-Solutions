// A sequence of l integers b1, b2, ..., bl (1 ≤ b1 ≤ b2 ≤ ... ≤ bl ≤ n) is called good if each number divides (without a remainder) by the next number in the sequence. More formally  for all i (1 ≤ i ≤ l - 1).

// Given n and k find the number of good sequences of length k. As the answer can be rather large print it modulo 1000000007 (109 + 7).

// Input
// The first line of input contains two space-separated integers n, k (1 ≤ n, k ≤ 2000).

// Output
// Output a single integer — the number of good sequences of length k modulo 1000000007 (109 + 7).





// Construct k numbers
// each number is bi from [1,n]

// n = 24
// k = 10

// 1 2 4 8 16 16 ... 

// 1 4 8 8 



// find all such sequences
// 1             k : k elements


// State : (i,j) : length of size i, and last element is j

// return the count of valid sequences
//         j 
// [       i]       ]  

// transition dp[i][j] =  sum dp[i-1][k st j%k == 0]

// dp[i][j] = dp[i-1][k1] + dp[i-1][k2] + ...... dp[i-1][j]
// all factors of j : cbtr(j) : cbrt(n) sqrt(n)


// dp[0][anything] = 0;
// dp[1][anything] = 1 : count of length 1 where the last element is 1<=j <= n is 1 as 1 element

// final ans
// dp[k][1] + dp[k][2] + ... dp[k][n]

// cnt of all sequences if lenth k where the lat element is 1,

#include <bits/stdc++.h>
using namespace std;

// Iterative Dp : Use a prefix from 0 to i
// Recursive : Use a suffix from i to n
//      j : prev element
// [     [i     ]
// length from i to k such that prev element is j

// dp[k+1][anything] = 0
// dp[k][anything] = 1
// dp[i][j] = sum of dp[i+1][j] + dp[i+1][2*j] + .. dp[i+1][k*j] where k*j <= n


const long long mod = 1e9+7;

int main(){

   int n;
   int k;
   cin >> n >> k;
   vector<vector<long long>> dp(k+1, vector<long long>(n+1,0));

// dp[i][j] : represent the cout of all sequences of length i with last element as j

//    for(int i=1;i<=n;i++) dp[1][i] = 1;
   
//    for(int i=2;i<=k;i++){
        
//       for(int j=1;j<=n;j++){
//           long long count = 0;
//           for(int factor = 1; factor * factor <= j ; factor++) {
//               if( j % factor == 0 ) {
//                   count = ( count + dp[i-1][factor] ) % mod;
//                 int p = j/factor;
//                   if(factor != p) count = ( count + dp[i-1][p] ) % mod;
//               }
//           }
//            dp[i][j] = count;
//       }
//    }
   
//    long long ans = 0;
//    for(int i=1;i<=n;i++){
 
//       ans = ( ans + dp[k][i] ) % mod;
//    }
   
//    cout << ans << endl;

for(int i=1;i<=n;i++) dp[k][i] = 1;
   
   for(int i=k-1;i>=1;i--){
        
      for(int j=1;j<=n;j++){
          long long count = 0;
          for(int multiple = j; multiple <= n ; multiple += j) {
                count = ( count + dp[i+1][multiple] ) % mod;
            }
            dp[i][j] = count;
        }
      }
   
   long long ans = 0;
   for(int i=1;i<=n;i++){
 
      ans = ( ans + dp[1][i] ) % mod;
   }
   
   cout << ans << endl;
   return 0;

}

