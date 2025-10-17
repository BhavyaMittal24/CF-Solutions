#include<bits/stdc++.h>
using namespace std;

const long long mod= 998244353;

int main(){

 int n;
 cin >> n;
    vector<int> a(n), b(n);
 for(int i=0;i<n;i++) cin >> a[i];

 for(int i=0;i<n;i++) cin >> b[i];


 int maxj = max(a.back(), b.back()) +1;
// dp[i][v] : no of ways tp generate sequence from I to n-1 such that preceding element is v
 vector<vector<long long>> dp(n+1, vector<long long>(maxj, 0));

 // dp[n][v] = 0;

 // at any I

 // dp[i][v] = dp[i+1][j] for all j >= v and  ai<=j <= bi   

 vector<long long> prefix(maxj,0);
  vector<long long> prefix1(maxj,0);

 // sum of dp[i+1][j] : prev index between a[i-1] to b[i-1]

 for(int v=a[n-1]; v<=b[n-1];v++){
    dp[n][v] = 1;
    if(v == 0) prefix[v] = dp[n][v] % mod;
    else prefix[v] = (prefix[v-1] + dp[n][v]) % mod;
 }
 for(int i=n-1;i>=1;i--){
    
    for(int v=a[i-1]; v<=b[i-1];v++){
        int left = max(v, a[i]);
        int right = b[i];

        dp[i][v] = (prefix[right] - (left > 0 ? prefix[left-1] : 0) + mod ) % mod;
        if(v == 0) prefix1[v] = dp[i][v] % mod;
        else prefix1[v] = (prefix1[v-1] + dp[i][v]) % mod;
        // for(int j=a[i]; j<= b[i]; j++){
        //   if( j >= v) {
        //      dp[i][v] =  (dp[i][v] + dp[i+1][j] ) % mod ;
        //   }
        // }
    }
    prefix = prefix1;
    fill(prefix1.begin(), prefix1.end(), 0);
 }
 
 long long cnt = 0;
 
 for(int i=a[0];i<=b[0];i++){
    cnt = (cnt + dp[1][i] ) % mod;
 }

 cout << cnt << endl;
 return 0;

}