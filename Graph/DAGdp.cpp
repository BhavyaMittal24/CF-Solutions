#include<bits/stdc++.h>
using namespace std;


// One major differecne witth DP on trees is we don't need a visited array there
// Because in Trees, each node can be visited only once as there is only one parent and I can reach from the parent to it's child only

// p1 ---> c1 , c2 , c3

// We need a visited array because each problem can be solved multiple times : or in other words each node can be visited by many nodes 
// 1 node can have multiple indegree ; indegree[node] > 1 because of which we arrive at same state ans use a viisted array to check if that value has been calauculatd or not
void dfs( int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &val, vector<long long> &dp){
    vis[node] = 1;

    //if( dp[node] != -1) return;

    dp[node] = val[node];
     for(int x : adj[node]){
        // if we don't have the value for the children, we call dfs and get the value
        if(vis[x] == 0){
            dfs(x, adj, vis, val, dp);
        }
        dp[node] = max(dp[node], val[node] + dp[x]);
    }
    return;
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
        indegree[v]++;
    }

    vector<int> val(n+1, 0);
    for(int i = 1; i <= n; i ++){
        cin >> val[i];
    }

    // find the max score for any path starting from any given node
    // score = max sum of all nodes along the path

    vector<long long> dp(n+1, -1);

    vector<int> vis(n+1, 0);

    long long maxPath = 0;

    // Using DFs to solve the problem for the max path starting from each node in a DAG

    // for(int i = 1; i <= n ; i++){
    //     if(vis[i] == 0){
    //         dfs(i, adj, vis, val, dp);
    //     }
    //     maxPath = max(maxPath, dp[i]);
    // }


    // Option 2 : Use a toposort to get the answer

    vector<int> topo;
    queue<int> q;

    for(int i = 1; i <= n ; i ++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }


    while( !q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(int x : adj[node]){
            indegree[x] --;

            // indegree[x] for that neighboir becomes 0 : we relax all the nodes of the node which is popped
            if( indegree[x] == 0){
                q.push(x);
            }
        }
    }
    // We get the order of the tout in the descending order

    // u->v : u comes before v in this ordrign for this DAG

    // If we travel from right to left, we have the order for going backwards :  u -> c1 -> cn

    for(int i = n-1; i >= 0 ; i--){

        int node = topo[i];

        dp[node] = val[node];
        for(int x :adj[node]){
            dp[node] = max(dp[node] , val[node] + dp[x]);
        }
        maxPath = max(maxPath, dp[node]);
    }

    cout << maxPath << endl;

    for(int i = 1; i <= n ; i ++){
        cout << i << " " << dp[i] << endl;
    }
    return 0;

}