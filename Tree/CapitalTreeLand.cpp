#include<bits/stdc++.h>
using namespace std;

int minInv = INT_MAX;

//minInversions[i] : min amount of edge flips required to make all edges down in a subtree of i

void dfs(int node, int parent, vector<vector<int>> &adj, vector<set<int>> &dir_adj, vector<int> &minInversions){

    // node -> x :path in a tree
    for(int x : adj[node]){
        if( x != parent){
            dfs(x, node, adj, dir_adj, minInversions);

            minInversions[node] += minInversions[x];

            if( dir_adj[node].find(x) == dir_adj[node].end()) {
                minInversions[node] ++;
            }
        }
    }
}

void changeRoot( int currRoot, int newRoot, vector<int> &minInversions, vector<set<int>> &dir_adj){

    // we change the state for the newRoot and currRoot so that the newRoot has the latest values
    minInversions[currRoot] -=minInversions[newRoot];

    if(dir_adj[currRoot].find(newRoot) == dir_adj[currRoot].end()){
        minInversions[currRoot] --;
    }

    else {
        minInversions[newRoot] ++;
    }

    minInversions[newRoot] += minInversions[currRoot];    
}

void reroot(int node, int parent, vector<vector<int>> &adj, vector<set<int>> & dir_adj, vector<int> &minInversions, vector<int> &dp){
    dp[node] =  minInversions[node];

    minInv = min(minInv, dp[node]);

    for(int x : adj[node]){

        if( x != parent){
            changeRoot(node, x, minInversions, dir_adj);
            reroot(x, node, adj, dir_adj, minInversions, dp);
            changeRoot(x, node, minInversions, dir_adj);
        }
       
    }
}

void reroot1(int node, int parent, vector<vector<int>> &adj, vector<set<int>> & dir_adj, vector<int> &minInversions, vector<int> &dp){
    // dp[node] =  minInversions[node];

    minInv = min(minInv, dp[node]);

    for(int x : adj[node]){

        if( x != parent){
            
            int minInvForRoot = dp[node] - minInversions[x];
            if(dir_adj[node].find(x) != dir_adj[node].end()) {
                dp[x] ++;  
            }
            else {
                minInvForRoot --;
            }

            dp[x] += (minInvForRoot + minInversions[x]); 
            reroot1(x, node, adj, dir_adj, minInversions, dp);
        }
       
    }
}

int main(){

    int n;
    cin >> n;

    // vector of sets for each i -> storing the directed edges
    vector<set<int>> dir_adj(n+1);

    vector<vector<int>> adj(n+1);

    for(int i = 0 ; i < n-1; i ++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);

        dir_adj[u].insert(v);
    }

    // min amount of edges to reverse to have all paths down for a subtree rooted at i//
    vector<int> minInversions(n+1, 0);

    dfs(1, 0, adj, dir_adj, minInversions);


    vector<int> dp(n + 1, 0);

    dp[1] = minInversions[1];
    reroot1(1, 0, adj, dir_adj, minInversions, dp);

    cout << minInv << endl;

    for(int i = 1; i <= n ; i ++){
        if( dp[i] == minInv) {
            cout << i << " ";
        }
    }
    //cout << endl;
    return 0;
}