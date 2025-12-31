#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 +7;

const int N = 2e5+1;

int dp[N] ;

void dfs(int node, vector<int>& vis, vector<vector<int>> &adj, vector<long long>& cntWays){
    vis[node] = 1;

    for(int x : adj[node]){
        if( !vis[x]) {
            dfs(x, vis, adj, cntWays);
        }
        cntWays[node] = (cntWays[node] + cntWays[x]) % mod;
    }    
}

long long ways( int node, vector<vector<int>> &adj){

    int n = adj.size() -1;
    if( node == n) {
        return 1;
    }

    if( dp[node] != -1) return dp[node];

    long long ans = 0;
    for(int x : adj[node]){
        ans = (ans + ways(x, adj)) % mod;
    }

    return dp[node] = ans;
}
int main(){

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);

    for(int i = 0 ; i < m ; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    memset(dp, -1, sizeof(dp));
    // vector<long long> cntWays(n+1,0);

    // vector<int> vis(n+1, 0);
    // cntWays[n] = 1;
    // vis[n] = 1;

    // for(int i = 1; i <= n ; i ++){
    //     if( !vis[i]) dfs( i, vis, adj, cntWays);
    // }

    // cout << cntWays[1] << endl;

    cout << ways(1, adj) << endl;


    return 0;

}