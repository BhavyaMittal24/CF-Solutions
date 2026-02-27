#include<bits/stdc++.h>
using namespace std;


void dfs(int node, int parent, vector<vector<pair<int,int>>> & adj, vector<vector<int>> &dp){

    // weight of an edge from node to it's parent

    vector<int> children;
    for(auto x : adj[node]){
        int child = x.first;
        int weight = x.second;

        if( child != parent){
            dfs(child, node, adj, dp);
            dp[node][0] += max(dp[child][0], dp[child][1]);
            children.push_back(weight + dp[child][0]);
        }    
    }

    int i = 0;
    for(auto x : adj[node]){
        int child = x.first;
        int weight = x.second;

        if( child != parent){
            children[i] +=  dp[node][0] - max(dp[child][0], dp[child][1]); 
            dp[node][1] = max(dp[node][1], children[i]);
            i++;
        }
    }
    
}
int main(){

    int n;
    cin >> n;

    // nodes from 1 to n
    // edges[i] : {parenti, wi}

    vector<vector<pair<int,int>>> adj(n+1);

    // vector<vector<int>> edges(n+1);

    for(int i = 1; i < n; i ++){
       
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    // made the adj list

    // dp[node][0] 
    // dp[node][1]

    vector<vector<int>> dp(n+1, vector<int> (2, 0) );

    dfs(1,0, adj, dp);
    cout << max(dp[1][0], dp[1][1]);

    return 0;
}