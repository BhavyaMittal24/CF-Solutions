// Pythagorean triplets

#include<bits/stdc++.h>
using namespace std;

// 1<=a, <= b <= c <= n <= 1e9
// a = 3 b = 4 c = 5
// number of triplets that satisfy c = a2-b , c2 = a2 + b2
// c2 = c + b + b2
// c2-c = b + b2
// c(C-1) = b(1+b)
// c = 6, b = 5, a = perfect square
//  f(x) = T if there exists total triplets >= x
// find the numbner of odd perfect squares <= n


void solve(int n){
  long long low = 3;
  long long high = n;
  long long mid;
  long long ans = -1;

// find the last odd square number < n
// TTTTTTTTTTTFFFFFFFFFF
  while(low <=high){
    mid = (low + high)/2;
    if( mid % 2 == 0){
      mid--; // make it odd
    }
    long long c = mid*mid/2 +1;
    // (bigger number)
    if(c <= n){
      // mid is the ith odd number : 1, 3, 5, 7, ...
      ans = mid/2;
      low = mid+2; 
    }
    else {
      high = mid-2;
    }
  }
  long long totalTriplets = (ans != -1) ? ans : 0;
  cout << totalTriplets << endl;
}

int main(){

// search for c;
 int t;
 cin >> t;
 while(t--){
   int n;
   cin >> n;
   solve(n);
 }
return 0;
}