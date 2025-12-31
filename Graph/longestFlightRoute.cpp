#include<bits/stdc++.h>
using namespace std;

void dfs( int node, vector<int> &vis, vector<vector<int>> &adj, vector<int>& child, vector<int> & dp){

    vis[node] = 1;

    int maxChild = 0;
    for(int x : adj[node]){
        if( vis[x] == 0){
            dfs(x, vis, adj, child, dp);
        }
        if( dp[maxChild] < dp[x]){
            maxChild = x;
        }
    }

    if( dp[maxChild] > 0) {
        dp[node ] = dp[maxChild] + 1;
        child[node] = maxChild;
    }
}

int main(){

    int n , m;
    cin >> n >> m;

    vector<int> child(n+1, -1);

    vector<vector<int>> adj(n+ 1);
    for(int i = 0 ; i < m; i ++){
        int u, v;
        cin >> u >> v;

        // u -> v
        adj[u].push_back(v);
    }

    child[n] = n + 1; 

    // dp[i] = max no of nodes in the path from  node i to n
    // final answer : dp[1];
    // transition : dp[u] = max(dp[c1], dp[c2], .. ) > 0 : max(dp[c]) + 1 : 0

    vector<int> dp(n + 1, 0);

    dp[n] = 1;
    // we use vector vis for konowing that part of dag has been solves or not

    vector<int> vis(n+1, 0);


    dfs(1, vis, adj, child, dp);

    if( dp[1]){
        cout << dp[1] << endl;

        int node = 1;
        while( node != (n+1)){
            cout << node << " ";
            node = child[node];
            if( node == -1) break;
        }
        cout << endl;
    }

    else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}