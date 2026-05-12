#include<bits/stdc++.h>
using namespace std;

void cntBalance(int node, int parent, vector<pair<int,int> > &dp, vector<vector<int> > &adj, int &ans, string &s){

    int cntBlack = 0;
    int cntWhite = 0;

    if(s[node-1] == 'W') cntWhite++;
    else cntBlack++;

    for(int x : adj[node]){
        if( x!= parent){
            cntBalance(x, node, dp, adj, ans, s);
            cntBlack += dp[x].first;
            cntWhite += dp[x].second;
        }
    }

    if(cntBlack == cntWhite) ans++;

    dp[node] = {cntBlack, cntWhite};
}


void solve(){

    int n;
    cin >> n;

    vector<vector<int> > adj(n+1);

    for(int i = 2; i <= n; i ++){
        int x;
        cin >> x;
        // x is the parent of i
        adj[i].push_back(x);
        adj[x].push_back(i);
    }

    string s;
    cin >> s;
    int ans = 0;

    // cnt the no of balanced subtrees

    vector<pair<int,int> > dp(n+1);
    // dp[i] = {cnt white nodes, cnt black nodes}

    cntBalance(1,0,dp, adj, ans, s);
    cout << ans << "\n";
    return;
}

int main(){

    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        solve();
    }
    return 0;
}