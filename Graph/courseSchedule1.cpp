#include<bits/stdc++.h>
using namespace std;


vector<int> ans;

// checkfor cycles in a directed graph 
bool isCycle = false;

void dfs( int node, vector<int> &vis,  vector<vector<int>> & adj){
    vis[node] = 2;

    for(int x : adj[node]){
        if( vis[x] == 0){
            dfs(x, vis, adj);
        }
        else if(vis[x] == 2){
            isCycle = true;
            return;
        }
    }

    vis[node] = 1;
}

// dfs to use the topolgoical sort only wokts for a connected componnt ; or for a component which has the indegree as 0. that is the starting node
void indegreeDFS( int node,  vector<int>& ccPath, vector<int> &vis,  vector<vector<int>> & adj){
    vis[node] = 1;

    for(int x : adj[node]){
        if( vis[x] == 0){
            indegreeDFS(x, ccPath, vis, adj);
        }
    }
    ccPath.push_back(node);
}


int main(){

    int n, m;

    cin >> n >> m;
    vector<vector<int>> adj(n+1);

    vector<int> indegree(n+1, 0);
    for(int i = 0 ; i < m ; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v] ++;
        // u -> v : edge going from u to v
    }

    vector<int> vis(n+1,0);

    for(int i = 1 ; i <= n ; i ++){
        if( !vis[i]){
            dfs(i, vis, adj);
            if(isCycle) break;
        }
    }

    if(isCycle) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }


    // indegree 
    vis.resize(n+1, 0);

    for(int i = 1; i <= n ; i++){
        if( indegree[i] == 0) {
            vector<int> ccPath;
            indegreeDFS(i, ccPath, vis, adj);
            reverse(ccPath.begin(), ccPath.end());

        }
    }
    // use a pq if you want lexorgraphgical order for the ordering

    for(auto it : ans) cout << it << " ";
    return 0;
}