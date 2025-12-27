#include<bits/stdc++.h>
using namespace std;

void dfs(int node, stack<int>& s, vector<int> &vis, vector<vector<int>> &adj){

    s.push(node);

    while( !s.empty()){
        // the first element is pushed to the stack, then printed and then popped. It's children are pushed in opposite manner
        int topNode = s.top();
        vis[topNode] = 1;
        cout << topNode << endl;
        s.pop();

        // push in the reverse order so that first popped is the first element of the adj list
        int nSize = adj[topNode].size();
        for(int i = nSize -1 ; i >= 0 ; i --){
            if(!vis[adj[topNode][i]]){
                s.push(adj[topNode][i]);
            }
        }
    }
}

int main(){

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);

    for( int i = 0 ; i < m; i ++){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    stack<int> s;
    vector<int> vis(n+1, 0);

    // implement an iterative dfs;
    for(int i = 1; i <= n; i ++){
        if( vis[i] == 0){
            dfs(i, s, vis, adj);
        }
    }

    return 0;
}