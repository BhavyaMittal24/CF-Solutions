// n, k 
// n ropes cut into k equal pieces
// n,k <= 1e4

// find the maximun length of each equal piece

#include<bits/stdc++.h>
using namespace std;

// possible candidate answers can be  : 
// 1 to 1e7 : 
//  k = n  ~ around 1e4
// prescision upto 1e-7


bool isPossibleToCutIntoKPiecesOfEqualLength(double mid, vector<int> &ropes, int k){
 long long count = 0;
 for( auto rope : ropes){
    count += (rope)/ mid;
 }
 return count >= k;
}

int main(){
  int n,k;
  cin >> n >> k;
  vector<int> ropes(n);
  for(int i=0;i<n;i++) cin >> ropes[i];
  
  double precision = 1e-7;
  double low = 0;
  double high = 1e7;
  // Search space  : 1 …. 1e5 and bw them is 1e-7 between each integer
  // 0(log 1e5 * 1e7) ~ 50 iterations;
  double mid = 0;
  double ans = -1;
  //TTTTTTTTTTTTTFFFFFFF
  for(int i=0;i<100;i++){
     mid = low + (high-low)/2;
     if(isPossibleToCutIntoKPiecesOfEqualLength(mid,ropes,k)){
        ans = mid;
        low = mid + precision;
     }
     else {
        high = mid - precision;
     }
  }
  cout << fixed << setprecision(7);
  cout <<  ans << endl;;
  return 0;
}