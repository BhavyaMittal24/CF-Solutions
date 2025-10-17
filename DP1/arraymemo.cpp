#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9+7;

vector<vector<long long>> dp;

// f(i, v) : cnt of all valid subarrays from i to n-1 such that v is the prev element 
long long count(int i, int v,vector<int> &arr, int n, int m){
    
   if(i == n)  return 0;  
   if( i == n-1){
       if(arr[i] == 0){
          int cnt = 1;
          if(v+1 <=m ) cnt++;
          if(v-1 >= 1) cnt ++;
          return cnt;
       }
       else{
         if(abs(arr[i] - v) <=1) return 1;
         return 0;
       }
   }
   
   if(arr[i] != 0){
      if(abs(arr[i] - v) > 1) dp[i][v] = 0;
      else dp[i][v] = count(i+1,arr[i],arr,n,m);
   }
   else {
      dp[i][v] = count(i+1,v,arr,n,m); ;
      if(v+1 <=m) dp[i][v] += count(i+1,v+1,arr,n,m);
      if(v-1>= 1) dp[i][v] += count(i+1,v-1,arr,n,m);
   }
   return dp[i][v];
}

// 1 5

// 0
int main(){

    int n,m;
    cin >> n >> m;

    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];

    dp =  vector<vector<long long >> (n, vector<long long>(m+1,-1));

    long long ans = 0;
    if(arr[0] != 0){
         ans = count(1,arr[0],arr,n,m);
    }

    else {
       for(int j=1;j<=m;j++){
          ans = (ans + count(1,j,arr,n,m)) % mod;
       }
    }

    cout << ans << endl;
    return 0;

// 

}