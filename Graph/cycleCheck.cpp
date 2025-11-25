#include<bits/stdc++.h>
using namespace std;

// find the no of connect componennts
bool isCycle = false;

void dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &vis){

    vis[node] = 1;
    for(int x : adj[node]){
        if(!vis[x]) dfs(x, node, adj, vis);
        else if( x != parent){
            isCycle = true;
        }
    }
}

int main(){
    int n,m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);

    vector<int> cntComponent;
    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n+1,0);
    dfs(1,0,adj,vis);
    cout << isCycle << endl;
    return 0;
}