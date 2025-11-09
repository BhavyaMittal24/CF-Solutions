#include<bits/stdc++.h>
using namespace std;


// BFS traversal

int main(){

    int n;
    cin >> n;
    // nodes from 1 - n

    vector<vector<int>> adj(n+1);

    // n-1 edges : n nodes
    for(int i=0;i<n-1;i++){
        int u;
        int v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // level by level traversal : where if A come before B, then children of B should come after children of A

    queue<int> q;
    vector<int> vis(n+1,0);
    // how to skip the parent, it should not be again added to the stack, so what to do for that?
    // We can check for the parent, by having an adj list with us

    q.push(1);
    vis[1] = 1;

    vector<int> bfs;
    while(!q.empty()){
        int currNode = q.front();
        q.pop();
        bfs.push_back(currNode);
        for(int neighbour : adj[currNode]){
            if( vis[neighbour] != 1){
                q.push(neighbour);
                vis[neighbour] = 1;
            }
        }
    }

    for(auto it : bfs){
        cout << it << " ";    
    }
    return 0;
}