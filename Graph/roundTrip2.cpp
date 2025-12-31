#include<bits/stdc++.h>
using namespace std;


vector<int> toposort;

void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, vector<int>& component, bool getSCC){

    vis[node] = 1;

    if(getSCC) {
        component.push_back(node);
    }

    for(int x : adj[node]){
        if( vis[x] == 0){
            dfs(x, vis, adj, component, getSCC);
        }
    }

    if( !getSCC){
        toposort.push_back(node);
    }
}

vector<int> ans;

void findPath(int root, int node, vector<int> & vis, vector<int>& pathVis,  vector<vector<int>> &adj){

    vis[node] = 1;

    pathVis.push_back(node);
    for(int x : adj[node]){

        if( vis[x] == 0){
            findPath(root, x, vis, pathVis, adj);
        }
        else if(x == root){
            pathVis.push_back(root);
            ans = pathVis;
            pathVis.pop_back();
        }
    }
    pathVis.pop_back();
}

// given a scc, find a shortest cyclic path from the node to itlsef. 
// In a scc, we have a path to go from that node to itslef

vector<int> findShortesCycle ( int node, vector<vector<int>> &adj){

    int n = adj.size() -1;
    vector<int> parent(n+1, 0);

    vector<int> vis( n+1, 0);

    int lastNode = -1;
    queue<int> q;
    q.push(node);
    vis[node] = 1;

    parent[node] = -1;

    while( !q.empty() && lastNode == -1){
        int topnode = q.front();
        q.pop();

        for(int x : adj[topnode]){
            if( vis[x] == 0){
                q.push(x);
                vis[x] = 1;
                parent[x] = topnode;
            }
            else if(x == node){
                lastNode = topnode;
                break;
            }
        }
    }

    vector<int> path;

    path.push_back(node);
    while(lastNode != -1){
        path.push_back(lastNode);
        lastNode = parent[lastNode];
    }

    reverse(path.begin(), path.end());
    return path;
}
int main(){

    // n nodes , m edges which are directed
    // AIM : find the largest SCC where you can start and end at the same node

    // find the SCC with a size  > 1 and print all the nodes for that SCC

    // Each SCC is a directed cycle in itself

    // SCC1 -> SCC2 -> SCC3 : do dfs and find the toposort ordering : rough toposort : based on the sorted tout time in descending order

    // reverse the edges : scc1 <- scc2 <- scc3

    // do the dfs on rev_edges on the toporoted based on the sorted tout time in desc order 

    // for each scc : that is dictinct island : get the components stored and the size 
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);

    vector<vector<int>> rev_adj(n+1);

    for(int i = 0; i < m ; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }

    vector<int> vis(n+1, 0);

    for(int i  = 1; i <= n; i ++){
        if(vis[i] == 0){
            dfs(i, vis, adj, vis, false);
        }
    }

    reverse(toposort.begin(), toposort.end());

    fill( vis.begin(), vis.end() ,0);

    for(int node : toposort){

        if( vis[node] == 0){
            vector<int> component;

            dfs( node, vis, rev_adj, component, true);

            if(component.size() > 1) {
                // for(int i  : component) cout << i << " ";
                // cout << endl;
                vector<int> newVis(n+1, 0);
                vector<int> pathVis;
                //findPath(node, node, newVis, pathVis, adj);

                ans = findShortesCycle(node, adj);
                //for(int i : ans) cout << i << " ";
                break;
            }
        }
    }

    if( ans.size() <= 1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }


    cout << ans.size() << endl;
    for(int node : ans){
        cout << node << " ";
    }

    return 0;
}
