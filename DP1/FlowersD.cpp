#include<bits/stdc++.h>
using namespace std;

long long const mod = 1e9+7;

int main(){

    int t;
    cin >> t;

    int k;
    cin >> k;

    vector<pair<int,int>> query(t);
    for(int i=0;i<t;i++){
        int u,v;
        cin >> u >> v;
        query[i] = {u,v};
    }

    int N = 1e5;
    vector<long long >dp(N+1,0);

    dp[0] = 1;

    vector<long long> prefixSum(N+1,0);
    prefixSum[0] = 1;
    for(int i=1;i<=N;i++){
        dp[i] = dp[i-1];

        if(i >=k) dp[i] = (dp[i] +  dp[i-k]) % mod;
        prefixSum[i] = (prefixSum[i-1] + dp[i]) %mod;
    }

    for(int i=0;i<t;i++){
        int u = query[i].first;
        int v = query[i].second;

        long long ans  = (prefixSum[v] - prefixSum[u-1] + mod) % mod;
        cout << ans << endl;
    }

    return 0;
}