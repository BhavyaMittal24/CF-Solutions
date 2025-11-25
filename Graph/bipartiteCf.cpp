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
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);

    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // col1, col2
    vector<int> col(n+1,0);
    // color the first node as 0
    vector<int> vis(n+1,0);

    dfs(1,vis,adj,col, 0);

    int cntColor1 = 0;
    for(int i=1;i<=n;i++){
        if(col[i] == 0){
            cntColor1++;
        }
    }

    int cntColor2 = n - cntColor1;

    long long ans = 1ll*cntColor1*cntColor2 - (n-1);
    cout << ans << endl;
    return 0;
}