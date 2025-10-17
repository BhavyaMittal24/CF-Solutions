#include<bits/stdc++.h>
using namespace std;

// gcd(a,b) = gcd(b,a-b)
long long  gcd(long long  a, long long b){
   while(b>0){
      a = a % b;
      swap(a,b);
   }
   return a;
}

void solve(){
  int n;
  cin >> n;
  vector<int> a(n);
  vector<long long> prefix(n,0);
  for(int i=0;i<n;i++) {
     cin >> a[i];
     if(i==0) {
       prefix[i] = a[i];
       continue;
     }
     prefix[i] = prefix[i-1] + a[i]; 
 }
 ///
 long long maxGCD = -1;
 for(int i=0;i<n-1;i++){
    long long b1 = prefix[i];
    long long b2 = prefix[n-1] - prefix[i];
    maxGCD = max(maxGCD, gcd(b1,b2));
 }
 cout << maxGCD<< endl;
 
  // gcd (a1,a2, … an) <= gcd(a1,a2 .. an-1)  <= gcd(a1,a2)
  // as we reduce the numbrr of elements, the gcd also increases
// as we inc the no of elements in the arrau, the gcd decreases
// now for making split [b1, bn2. b3 … bn]
 // prefix sum = bi
  //  I want only 2 elements to be there hence only 2 subarrays
// now uestion is how to split?
 // gcd(a1,a2, ... a3)  has gcd  g
 // gcd(a1+a2, a3, a4, ...)  has a gcd >= g
 // g divides a1 and a2
 // 2,3,5 gcd = 1
 // 5,5 gcd = 1

}

int main(){

  int t;
  cin >> t;
  while(t--) solve();
  return 0;

}