// good sequences


// a1 a2 a3 … an

// n numbers called as good

// any seq is of the form

// xi x2 … xk
// xi  < xi+1  and gcd(xi, xi+1) != 1 they have a common factor


//length of longest good sequence possible from a1 a2 .. an numbers


///  2 3 4 6 9

// strictly increasing each element is distinct 
// [2 , 3
//    [2,  4, 6, 9
//    [2,  6
//    [2,  9 

// dp[i] : length og longest sequence starting from arr[i]
   // dp[i] = max(dp[i], 1 + dp[j]) // where j is a number which has common factors with I:
   // 0(n* gcd(I,j) : 

// n = 1e5
// ai <= 1e5
// tt for each state : i : n* log2(a) : 2*1e6 per state -> 0(1) or 0(log2n)
// map where I am storing pf for each ai
// a1 a2 ... an : a1 : all ai it shares factors with 
// primes less than 1e5 : n/logen : 1e5/15 : 104 
// p1 : a1,a2, a3 ... sorted manner
// p2 : a1, a3, a5, a6
// p3 :

//.. ai : logai -> all the pf : 


// map where all ais are present if they have that prime
//
// time for each state : 1e5* log(1e5)
// 
// 
// [3,

// [4,

// [6, 

#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b){
   while(b){
      a = a%b;
      swap(a,b);
   }
    return a;
}
int main(){

  int n;
  cin >> n;
  vector<int> arr(n);
  //int maxN = 0;
  for(int i=0;i<n;i++) {
     cin >> arr[i];
     //maxN = max(arr[i], maxN);
  }
 
 // dp[i]  : length of lomgest sequence starting from arr[i];
  vector<long long>dp(n+1,1);

  for(int i=n-2;i>=0;i--){
	for(int j=i+1;j<n;j++){
            if(gcd(arr[i], arr[j]) > 1) {
               dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
  }

  long long maxLen = 1;

  for(int i=0;i<n;i++){
    maxLen = max(maxLen, dp[i]);
  }  
  cout << maxLen << endl;
  return 0;
}//

// 2 3 4 6 9

// find all the non coprime numbers for each ai