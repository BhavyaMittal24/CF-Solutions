#include<bits/stdc++.h>
using namespace std;

bool isCycle = false;

vector<int> topoSort;
void dfs(int node, vector<int> & vis, vector<vector<int>> & adj){

    vis[node] = 2;

    for(int x : adj[node]){
        if( !vis[x]){
            dfs(x, vis, adj);
        }
        else if( vis[x] == 2){
            isCycle = true;
            return;
        }
    }

    vis[node] = 1;
    topoSort.push_back(node);
}

int main(){

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);

    for(int i = 0 ; i < m ; i ++){
        int u, v;
        cin >> u >> v;

        // u -> v 
        adj[u].push_back(v);
    }

    vector<int> vis(n+1, 0);
    for(int i = 1; i <= n; i ++){
        if( vis[i] == 0){
            dfs(i, vis, adj);
            if(isCycle == true) break;
        }
    }

    reverse(topoSort.begin(), topoSort.end());
    if(isCycle ){
        cout << "IMPOSSIBLE" << endl;
    }

    else {
        for(auto node : topoSort){
            cout << node << " ";
        }
    }

    return 0;
}