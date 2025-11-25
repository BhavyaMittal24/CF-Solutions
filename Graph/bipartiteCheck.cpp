#include<bits/stdc++.h>
using namespace std;

bool isBipartite = true;

void dfs(int curr, vector<int> &vis, vector<vector<int>> &adj, vector<int> &color, int currColor){
    vis[curr] = 1;
    color[curr] = currColor;

    for(int x : adj[curr]){
        if( !vis[x]){
            dfs(x, vis, adj, color, currColor^1);
        }
        else if(color[x] == currColor){
            isBipartite = false;
        }
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);

    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // col1, col2
    vector<int> col(n+1,0);
    // color the first node as 0
    vector<int> vis(n+1,0);

    dfs(4,vis,adj,col, 0);

    if(isBipartite){
        cout << "is bipartite " << endl;
    }
    else {
        cout << "The graph is not bipartite and has an odd length cycle" << endl;
    }
    return 0;
}