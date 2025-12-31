#include<bits/stdc++.h>
using namespace std;

vector<int> topo;

void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, vector<int>& component, bool getSCC){

    vis[node] = 1;

    if( getSCC){
        component.push_back(node);
    }

    for(int x : adj[node]){
        if( !vis[x]) dfs(x, vis, adj, component, getSCC);
    }

    if( !getSCC){
        topo.push_back(node);
    }
}

int main(){

    const long long mod = 1e9 +7;
    int n;
    cin >> n;

    vector<int> cost(n+1, 0);

    for(int i = 1; i <= n ; i++) cin >> cost[i];

    int m;
    cin >> m;

    vector<vector<int>> adj(n+1 );

    vector<vector<int>> rev_adj(n+1);

    for(int i = 0; i < m ;i ++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }

    vector<int> component;

    vector<int> vis(n+1, 0);

    for(int i = 1; i <= n ;i ++){
        if( vis[i] == 0){
            dfs(i, vis, adj, component, false);
        }
    }


    reverse(topo.begin(), topo.end() );

    fill(vis.begin(), vis.end(), 0);

    long long totalCost = 0;

    long long ans = 1;
    vector<int> cntMinCostNodes;
    for( int node : topo){

        if( vis[node] == 0){
            component = {};
            dfs(node, vis, rev_adj, component, true);

            int minCostNode = component[0];

            int cnt = 0;
            for(int x : component){
                if( cost[minCostNode]  > cost[x]){
                    cnt = 1;
                    minCostNode = x;
                }
                else if( cost[minCostNode] == cost[x]){
                    cnt++;
                }
            }

            totalCost += cost[minCostNode];

            ans = ( ans * cnt ) % mod;
        }
        
    }


    cout << totalCost << " " << ans << endl;
    return 0;
}