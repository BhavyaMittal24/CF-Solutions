// Block sequence

// Given a sequence of integers a
//  of length n
// .

// A sequence is called beautiful if it has the form of a series of blocks, each starting with its length, i.e., first comes the length of the block, and then its elements. For example, the sequences [3, 3, 4, 5, 2, 6, 1
// ] and [1, 8, 4, 5, 2, 6, 1
// ] are beautiful (different blocks are colored differently), while [1
// ], [1, 4, 3
// ], [3, 2, 1
// ] are not.

// In one operation, you can remove any element from the sequence. What is the minimum number of operations required to make the given sequence beautiful?

// Input
// The first line of the input contains a single integer t
//  (1≤t≤104
// ) — the number of test cases. Then follows the descriptions of the test cases.

// The first line of each test case contains a single integer n
//  (1≤n≤2⋅105
// ) — the length of the sequence a
// .

// The second line of each test case contains n
//  integers a1,a2,…,an
//  (1≤ai≤106
// ) — the elements of the sequence a
// .

// It is guaranteed that the sum of the values of n
//  over all test cases does not exceed 2⋅105
// .

//  n <= 2 * 1e5

// a block sequence

// 3 3 4 5 2 6 1

// find min no of operarion reqd to make it beautifil
// n = 6
// 3  4 1 6  7  7

// 1 element remove 3

// remove min elements = retain the maximum elements


// dp[i] : number of max elements retained in the array starting from i to n such that (the entire array is a seq of bful blocks) it is a seq of bful blocks

// to pick a[i] : n-1 - i  <= a[i]

//   i           n-1
// 1 4 5 2 3 7 9 1

// 0 1 2 3 4 5
// for each ai, i can have it removed from the sequence, or be a part of the seq

//             1 
//  -remove a[i]                 +keep a[i]
//    i+1                              1+i+a[i]
//    0 elements added                     a[i]+1 elements added

// dp[i] = max(dp[i+1], i+a[i] + dp[1+a[i]+i])

// ans = n - dp[0];

// dp[out of bounds] = 0;
// basically from i >=n, i have 0 elements

// iterate from rightt to left
// fill dp[n-1] first

#include<bits/stdc++.h>
using namespace std;

void solve(){
   int n;
   cin >> n;
   vector<int> a(n);
   for(int i=0;i<n;i++) cin >> a[i];
   
   vector<int> dp(n+1,0);
   // dp[i] = max size subsequence present in the array from i to n-1 such that this subsequence form a seq of bful blocks
   // which means it has blocks with length, followed by number of elements equal to the length of the block
   // [l1 a1 ... al1 ] [l2 a1 ... al2 ]
    
   for(int i=n-1;i>=0; i--){
      // we can take a[i] as a part of seq or skip it
      int skip;
      int pick =0;  
      skip = dp[i+1];
     
      // for picking a[i] I should have 1+a[i] elements more ahead
      if(i+1+a[i] <=n){
         pick += a[i]+1;
      }
      
      if(i+1+a[i] <= n-1)
    	pick += dp[i+1+a[i]];
     
     // SInce i want to find the maximum elements i can have
     dp[i] = max(skip, pick);
   }
   cout << n - dp[0] << endl;
}


int main(){
  int t; 
  cin >> t;
  while(t--) {
     solve();
  }
  return 0;
}