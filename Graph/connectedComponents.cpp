#include<bits/stdc++.h>
using namespace std;

// find the no of connect componennts

void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, int &sizeOfComponent){

    vis[node] = 1;
    sizeOfComponent++;
    for(int x : adj[node]){
        if(!vis[x]) dfs(x, adj, vis, sizeOfComponent);
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

    int cnt = 0;
    for(int i = 1; i <= n; i ++){
        if(vis[i] == 0){
            int sizeOfComponent = 0;
            dfs(i, adj, vis, sizeOfComponent);
            cnt ++;
            cntComponent.push_back(sizeOfComponent);
        }
    }

    cout << "Number of connected components is : " << cnt << endl;
    for(int i = 0; i < cntComponent.size(); i ++){
        cout << cntComponent[i] << " ";
    }
    return 0;
}