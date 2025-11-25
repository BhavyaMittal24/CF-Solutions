#include<bits/stdc++.h>
using namespace std;

int main(){

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    // vertices or nodes are indexed for a graph : 1 based indexing from 1 to n

    for(int i = 0; i < m; i ++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    vector<int> parent(n+1,0);
    vector<int> vis(n+1,0);
    
    parent[1] = 0;
    q.push(1);
    vis[1] = 1;
    int cnt = 1;

    while( (!q.empty()) && (vis[n] == 0) ){
        
        int qSize = q.size();
        // attempt to make it level by level
        // ensures that all nodes in a level are popped and at the end we have their children in queue ready to be executed in the exact order of their parents
        while(qSize--){
            int node  = q.front();
            q.pop();

            for(int neighbour : adj[node]){
                if( !vis[neighbour]){
                    vis[neighbour] =  1;
                    q.push(neighbour);
                    parent[neighbour] = node;
                }
            }
        }
        // when the new level +1 is pushed, i increment the count to mark the number of nodes in the path
        cnt++;
    }

    vector<int> path;


    int curr = n;
    while( curr != 0){
        path.push_back(curr);
        curr = parent[curr];
    }

    reverse(path.begin(), path.end());

    if(vis[n] == 0) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    cout << cnt << endl;
    for(auto i : path) cout << i << " ";
    return 0;
}