#include<bits/stdc++.h>
using namespace std;

bool isPossibleToReach(int k, vector<pair<int,int>>&segment){
   int n = segment.size();
   long long left = 0;
   long long right = 0;
   for(int i=1;i<=n;i++){
      if(max(left-k,1ll*segment[i-1].first) > min(right+k, 1ll*segment[i-1].second)) return false; 
      left = max(left-k, 1ll*segment[i-1].first);
      right = min(right+k, 1ll*segment[i-1].second);
   }
   return true;
}
int main() {
   int t;
   cin >> t;
   while(t--){
     int n;
     cin >> n;
     vector<pair<int,int>> segment(n);
     for(int i=0;i<n;i++){
        int l,r;
        cin >> l >> r;
        segment[i] = {l,r};
     }
     int low = 0;
     int high = 1e9;
     int mid =  0;
     int ans = -1;
     while( low <= high) {
       mid = low + (high-low)/2;
       if(isPossibleToReach(mid,segment)){
          ans = mid;
          high = mid-1;
       }
       else {
         low = mid+1;
       }
     } 
     cout << ans << endl;
   }
   return 0;
}