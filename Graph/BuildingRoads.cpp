#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &vis, vector<vector<int>> &adj){
    vis[node] = 1;

    for(int x : adj[node]){
        if(!vis[x]){
            dfs(x, vis, adj);
        }
    }
}

int main(){

    int n, m;
    cin >> n >> m;

    //m is of the order of n

    vector<vector<int>> adj(n+1);

    for(int i = 0 ; i < m; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n+1,0);

    vector<int> disjointIslands;
    for(int i = 1; i<= n; i++){
        if(!vis[i]){
            dfs(i,vis, adj);
            disjointIslands.push_back(i);
        }
    }

    cout << disjointIslands.size()-1 << endl;
    for(int i = 0; i < disjointIslands.size()-1; i++){
        cout << disjointIslands[i] << " " << disjointIslands[i+1] << endl;
    }

    return 0;
}