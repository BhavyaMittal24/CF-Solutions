#include<bits/stdc++.h>
using namespace std;

int cnt = 0;

// dp [i] [set ] -> value

// 
long long sumDis(int idx, vector<int> &vis, vector<long long> &s){
    
    cnt ++;
    int n = s.size();
    if(idx == 0){
        return 0;
    }

    long long maxi = 0;
    long long mini = 1e9+1;
    for(int i=0;i<n;i++){
        if(vis[i] == 1){
            maxi = max(maxi, s[i]);
            mini = min(mini, s[i]);
        }
    }

    long long ans = 1e18;
    for(int i=0;i<n;i++){
        if(vis[i] == 0){
            long long diff = max(maxi, s[i]) - min(mini, s[i]);
            vis[i] = 1;
            ans = min(ans, diff + sumDis(idx-1,vis,s));
            vis[i] = 0;
        }
    }
    return ans;
}

int main(){

    int n;
    cin >> n;
    vector<long long> s(n);
    for(int i=0;i<n;i++) cin >> s[i];


    vector<map<set<int>,long long>> dp(n+1);
    // dp[i]  is a map of [set] , [value]
    // mp[set]  has value as the ans;
    vector<int> vis(n,0);
    
    long long ans = sumDis(n,vis,s);
    cout << ans << endl;
    cout << cnt << endl;
    return 0;
}