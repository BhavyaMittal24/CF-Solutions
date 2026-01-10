#include<bits/stdc++.h>
using namespace std;

int lastlevel = 0;
void dfs(int node, int parent, vector<vector<int>> &adj, int distance, vector<int> &level){

    level[distance] ++;

    lastlevel = max(lastlevel, distance);

    for(int x : adj[node]){
        if( x != parent){
            dfs(x, node, adj, distance+1, level);
        }
    }
}

void solve(){

    int n;
    cin >> n;
    
    vector<vector<int>> adj(n+1);

    for(int i = 0 ; i < n; i ++){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> level(n);

    // array of size of height of tree
    

}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}