// Write your code here
#include<bits/stdc++.h>
using namespace std;

// do dfs foreach node  and find the tout time : post order traversal
void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, vector<int> &topo){

    vis[node] = 1;

    for(int x : adj[node]){
        if( !vis[x]) {
            dfs(x, vis, adj, topo);
        }
    }

    topo.push_back(node);
}

int minEdges = 0;

void dfsCycle(int node, vector<int> &vis, vector<vector<int>> &rev_adj){

    vis[node] = 1; // node is visited and is in path

    for(int x : rev_adj[node]){
        if( vis[x] == 0) {
            dfsCycle(x, vis, rev_adj);
        }

        else if(vis[x] == 1){
            minEdges ++;
            // cycle detected : I can reach x when i started from x
        }
    }

    vis[node]  =2; // visited but not in path
}

void solve(){

    int n;
    cin >> n;

    minEdges = 0;
    // directed graph
    vector<vector<int>> adj(n+1);

    vector<vector<int>> rev_adj(n+1);

    for(int i = 1; i <= n; i ++){

        for(int j = 1; j <= n; j ++){
            int edge;
            cin >> edge;

            if(edge){
                // i -> j both these edges are present
                adj[i].push_back(j);
                rev_adj[j].push_back(i);
            }
        }
    }

    vector<int> vis(n+1, 0);
    // vis array
    vector<int> topo;

    for(int i = 1; i <= n; i ++){
        if(!vis[i]) dfs(i,vis, adj, topo);
    }

// reverse the order for the toposort : based on the tout time desc order
    reverse(topo.begin(), topo.end());

    // find the scc and for each scc if a node comes in the visited path again : remove the edge : +1 then

    fill(vis.begin(), vis.end() , 0);

    for(auto node : topo){
        if(!vis[node] ) {
            dfsCycle(node, vis, rev_adj);
        }
    }
    
    cout << minEdges << "\n";
}

int main(){

    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}