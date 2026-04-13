#include<bits/stdc++.h>
using namespace std;


bool isPossible;


void dfs(int color, int node, vector<int> &vis, vector<int> & colors, vector<vector<int>> & adj){

    vis[node] = 1;
    
    colors[node] = color;
    
    for(int x : adj[node]){

        if( !vis[x]){

            dfs(color^1, x, vis, colors, adj );
        }
        else if(colors[x] == color ){
            isPossible = false;
        }
    }
}

int main(){

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);

    isPossible = true;

    for(int i = 0; i < m; i ++){

        int u, v;
        cin >>  u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> colors(n+1,0);

    vector<int> vis(n+1, 0);
    for(int i = 1; i <= n; i ++){

        if(!vis[i]){
            dfs(0,i,vis, colors, adj);
        }
    }

    if(!isPossible){
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for(int i = 1; i <=n; i ++){
        cout << colors[i] + 1 << " ";
    }

    cout << "\n";
    
    return 0;
}