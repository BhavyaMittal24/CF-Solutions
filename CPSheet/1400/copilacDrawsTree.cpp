#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<vector<int>> &adj, map<string,int> & order, vector<long long> & dp){

    if( node == 1){
        dp[node] = 1;
    }

    int cntEdgesComingBefore = 0;

    // pci , check if all pci come after p1 p

    long long maxChildren = 0;
    for(int x : adj[node]){

        if(x == parent) continue;

        dfs(x, node, adj, order, dp);
        
        string nodeParent = "";
        string nodeChild = "";

        if( node < parent){
            nodeParent += to_string(node) + "#" + to_string(parent);
        }
        else {
            nodeParent += to_string(parent) + "#" + to_string(node);
        }

        if(x < node){
            nodeChild += to_string(x) + "#" + to_string(node); 
        }
        else {
            nodeChild += to_string(node ) + "#" + to_string(x);
        }

        int childRank = order[nodeChild];
        int nodeRank =  order[nodeParent];

        if( childRank < nodeRank ) maxChildren = max(maxChildren, 1 + dp[x]);

        else maxChildren = max(maxChildren, dp[x]);
    }

    // if even one of the children comes before the parent node 
    // if no child comes before the parent gets in the rank orering

    //cout << node << " " << cntEdgesComingBefore << " "  << sumChildren << "\n";
   
    dp[node] = dp[node] + maxChildren;

    // forna laaf node , the ans is 0
}

void solve(){

    int n;
    cin >> n;

    // create a map for edges ordering
    // ui v1
    // p ci

    //map<string,int> order;
    vector<int> parentRank(n+1,-1);

    parentRank[1] = 0;
    parentRank[0] = -1;
    vector<vector<int>> adj(n+1);

    map<string,int> order;
    int rank = 1;
    for(int i = 0; i < n-1; i ++){
        int u, v;
        cin >> u >> v;

        if( u > v) swap(u,v);
        string edge = to_string(u) + "#" + to_string(v); // u#v

        order[edge] = rank;
        adj[u].push_back(v);
        adj[v].push_back(u);
        //order[edge] = rank;
        rank++;
    }

   
    // 0(N + sum of degi for all n nodes)
    vector<long long> dp(n+1, 0);

    dp[1] = 1;
    dfs(1,0, adj, order, dp);

    cout << dp[1] << "\n";
    // cnt of no of steps taken to form the netire subtree under he node i dp[i];
}
int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}