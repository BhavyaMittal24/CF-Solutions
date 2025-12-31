#include<bits/stdc++.h>
using namespace std;

vector<int> toposort;

void dfs( int node, vector<int> &vis, vector<vector<int>> & adj){
    vis[node]  = 1;

    for(int x : adj[node]){
        if( vis[x] == 0){
            dfs(x, vis, adj);
        }
    }

    // at the end of the traversal, I am pushing to the array
    toposort.push_back(node);
}

void dfs_scc(int node, vector<int> & vis, vector<vector<int>> & rev_adj, vector<int>& component, long long &sum, vector<int> &coins){
    vis[node] = 1;

    component.push_back(node);
    sum = sum + 1ll*coins[node];
    for(int x : rev_adj[node]){
        if( vis[x] == 0){
            dfs_scc(x, vis, rev_adj, component, sum, coins);
        }
    }
}


void maxCoins( int node, vector<vector<int>> & cond_adj, vector<int> & vis, vector<long long>& maxValue, vector<long long> & val){
    
    maxValue[node] = val[node];
    vis[node] = 1;
    for(int x: cond_adj[node]){

        if( vis[x] == 0){
            maxCoins(x, cond_adj, vis, maxValue, val);
        }
        maxValue[node] = max( maxValue[node], val[node] + maxValue[x]);
    }
}

int main(){

    int n , m;
    cin >> n >> m;

    vector<int > coins(n+1);

    for(int i = 1 ; i <= n ; i++) {
        cin >> coins[i];
    }

    vector<vector<int>> adj(n+1);
    vector<vector<int>> rev_adj(n+1);

    // n nodes , m unidrection edges of an undireced graph

    for(int i = 0 ; i < m ; i ++){
        int u, v;
        cin >> u >> v;

        // u -> v
        adj[u].push_back(v);

        // v -> u
        rev_adj[v].push_back(u);
    }

    vector<int> vis(n+1, 0);

    for(int i = 1; i <= n ; i ++){
        if( vis[i] == 0) dfs(i, vis, adj);
    }

    reverse(toposort.begin(), toposort.end());

    fill(vis.begin(), vis.end(), 0);

    // a vector of strongly connected components 
    // {cycle1 } , { cycle2 }, {cycle 3 } .... 
    vector<vector<int>> components;

    vector<int> roots(n+1, 0);
    vector<long long> val(n + 1, 0);

    int cnt = 1;
    for(auto node : toposort){

        //cout << node << " " << endl;;
        if( vis[node] == 0){
            vector<int> component;
            long long sum = 0;
            dfs_scc(node, vis, rev_adj, component, sum, coins);
            components.push_back(component);

            // setting new root for all the members of one scc
            for(int x : component){
                roots[x] = cnt;
            }
            // giving this one compressed node the value for the sum
            val[cnt] = sum;
            cnt ++;
        }
    }

    // form a new condensed graph;

    vector<vector<int>> cond_adj(n+1);

    for(int i = 1 ; i <= n ; i ++){
        for(int x : adj[i]){
            // i -> x
            // they both don;t belong to the same SCC
            if( roots[x] != roots[i]){
                // roots[i] -> roots[x]
                cond_adj[roots[i]].push_back(roots[x]);
            }
        }
    }


    // for(int i = 1; i <= n ; i ++){
        
    //     cout << i << " : ";
    //     for(int x : cond_adj[i]){
    //         cout << x << " ";
    //     }
    //     cout << " val :  " << val[i] ;
    //     cout << endl;
    // }

    vector<long long> maxValue(n+1 , 0);

    long long maxAns = 0;
    fill(vis.begin(), vis.end(), 0);

    for(int i = 1;  i<= n ; i ++){
        if( vis[i] == 0){
            maxCoins(i, cond_adj, vis, maxValue, val);
        }
        maxAns = max(maxAns, maxValue[i]);
    }


    cout << maxAns << endl;
    return 0;

}