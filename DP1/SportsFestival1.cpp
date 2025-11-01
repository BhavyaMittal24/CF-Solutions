#include<bits/stdc++.h>
using namespace std;

// COde is like the bitmast : can be solved using a bitmask
// simila to counting the number of permutations in an array 

// the problem gets reduced to counting the sum of disprepancy : and if the set of prev elements is same 
// simi;ar to what we had in the permuation problem

// dp[ 1100011] : these elements are previously selected : find the no of permutations more i can generate

// i have a smilar problem here as well after all, 
// dp[set <indices selected>] = min sum of discrepancies

// repeated subprobkems :
int cnt = 0;

// dp [i] [set ] -> value

long long sumDis(int idx, set<int> vis, vector<long long> &s,  vector<map<set<int>,long long>>& dp){
    
    cnt ++;
    int n = s.size();
    if(idx == 0){
        return 0;
    }

    // dp[idx] is a map which does not contain a key-value pair for the set of vis
    if(dp[idx].find(vis) != dp[idx].end()) return dp[idx][vis];

    long long maxi = 0;
    long long mini = 1e9+1;
    for(int i=0;i<n;i++){
        if(vis.count(i) != 0){
            maxi = max(maxi, s[i]);
            mini = min(mini, s[i]);
        }
    }

    long long ans = 1e18;
   
    for(int i=0;i<n;i++){
        if(vis.find(i) == vis.end()){
            long long newDiff = max(maxi, s[i]) - min(mini, s[i]);
            vis.insert(i);
            ans = min(ans, newDiff + sumDis(idx-1,vis,s,dp));
            vis.erase(i);
        }
    }
    return dp[idx][vis]  = ans;
}

int main(){

    int n;
    cin >> n;
    vector<long long> s(n);
    for(int i=0;i<n;i++) cin >> s[i];


    vector<map<set<int>,long long>> dp(n+1);
    // dp[i]  is a map of [set] , [value]
    // mp[set]  has value as the ans;
    set<int> vis;
    
    long long ans = sumDis(n,vis,s,dp);
    cout << ans << endl;
    //cout << cnt << endl;
    return 0;
}