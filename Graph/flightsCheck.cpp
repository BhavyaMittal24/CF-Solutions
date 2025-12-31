#include<bits/stdc++.h>
using namespace std;


void dfs( int node, vector<int> &vis, vector<vector<int>> &adj){
    vis[node] = 1;

    for(int x : adj[node]){
        if( !vis[x]){
            dfs(x, vis, adj);
        }
    }
}
int main(){
    int n , m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    vector<vector<int>> rev_adj(n+1);

    // n nodes , m unidrection edges of an undireced graph

    for(int i = 0 ; i < m ; i ++){
        int u, v;
        cin >> u >> v;

        // u -> v
        adj[u].push_back(v);

        // v -> u
        rev_adj[v].push_back(u);
    }

    vector<int> vis(n+1, 0);
    
    bool isSCC = true;

    int missingNode = 0;
    dfs(1, vis, adj);

    for(int i = 1; i <= n ; i++){
        if( vis[i] == 0) {
            isSCC = false;
            missingNode = i;
        }
    }

    if( !isSCC){
        cout << "NO" <<endl;
        cout << 1 << " " << missingNode << endl;
        return 0;
    }

    fill(vis.begin(), vis.end(), 0);

    dfs(1, vis, rev_adj);

    for(int i = 1; i <= n ; i++){
        if( vis[i] == 0) {
            isSCC = false;
            missingNode = i;
        }
    }

    if( !isSCC){
        cout << "NO" <<endl;
        cout << missingNode << " " << 1 << endl;
        return 0;
    }

    cout << "YES" << endl;

    return 0;
}