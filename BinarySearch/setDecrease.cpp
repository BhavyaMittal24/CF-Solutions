//Set or decrease


//steps : 0 to 1e18
// potential ansswers
// f(x) = T if sum is less than k in x steps
// f(x)  = T if ssteps >= x1

// FFFFFFFFFTTTTTTTTTTTTT

//steps can be ai = ai-1
//ai = aj

// is It possible to have sum <= k by transforming elements in mid steps

// a1 a2 a3 … ai ……  an

// m : total steps

// x          m-x steps
// a1-x          a1-x    a1-x (m-x) elements from behind
//S = S - x  - [ai - [a1-x] + ...     an - [a1-x]]
// S = S -x - [ SUm of last m-x terms] - (m-x) * [a1-x]
 

// new sum
// a1 a2 a3 … ai ……  an
// perform m operations
//  S - a1 + 0+1(a1-m)
//  S - a1 - an + (1+1)( a1 - (m-1));

//  S - a1 - an - an-1 + 3(a1 - (m-2));
       
// S - (a1 - ) + (n-1+1)( a1 - (m-(n-1)));
#include <bits/stdc++.h>
using namespace std;

// 1           ,,,,,
// x = 18 
// -17           ....
bool isPossible(long long steps, vector<int> &arr, long long k, long long sum){
   if( sum <= k) return true;
   if(sum - steps <=k) return true;
   long long tempSum = 0;
   long long sumOfLast = arr[0];
   long long n = arr.size();
   for(int i=0;i< min(n,steps);i++){
      tempSum = sum - sumOfLast + (1+i)*(arr[0] - (steps - i));
      sumOfLast += arr[arr.size()-1-i];
      if(tempSum <= k) return true;
   }
   return false;
}


void solve() {
  int n;
  long long k;
  cin >> n >> k;
  vector<int> arr(n);
  long long sum = 0;
  for(int i=0;i<n;i++) {
    cin >> arr[i];
     sum += arr[i];
  }
  sort(arr.begin(), arr.end());
  long long low = 0;
  long long high = 1e18;
  long long mid = 0;
  long long ans = -1;

  // FFFFFFFFTTTTTTTTTTTTT
  while(low <= high){
    mid = (low + high)/2;
    if(isPossible(mid,arr,k,sum)){
       ans = mid;
       high= mid-1;
    }
    else low = mid+1;
  }
  cout << ans << endl;
  
}

int main(){
  int t;
  cin >> t;
  while(t--){
    solve();
  }
  return 0;
}