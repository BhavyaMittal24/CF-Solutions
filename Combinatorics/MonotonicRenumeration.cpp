// intervalEndIndex

// currIdx : 
// map : arr[i] -> last occurence of a[i]

// idx 0 1 2 3 4
      
// arr 1 2 1 2 3

// b - 0 0 0 0 1
//     0 0 0 0 0

// 1 -2
// 2 -3
// 3 -4

#include<bits/stdc++.h>
using namespace std;

const long long mod = 998244353;

int main(){
   int n;
   cin >> n;
   vector<int> a(n);
   unordered_map<long long ,long long> mp;
   for(int i=0;i<n;i++) {
      cin >> a[i];
       mp[a[i]] = i;
   }

   long long endingIntervalIdx = mp[a[0]];

   long long ans = 1;
   for(long long i=0;i<n-1;i++){
    //  cout << "endingIntervalIdx: " << endingIntervalIdx << endl;
       if( mp[a[i]] > endingIntervalIdx){
         endingIntervalIdx = mp[a[i]];
       }
        if(i == endingIntervalIdx) {
          ans = ( ans * 2 ) % mod;
       }
   }

   cout << ans << endl;
   return 0;
}