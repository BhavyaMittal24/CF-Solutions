#include<bits/stdc++.h>
using namespace std;

// updates the min cost required to reach all the towns from towns of type i
void bfs( vector<int> towns, int type , vector<vector<int>> &cost, vector<vector<int>> &adj){
    
    queue<int> q;
    int n = cost.size() -1;
    vector<int> vis(n+1,0);

    for(int i = 0 ;i < towns.size(); i ++){
        cost[towns[i]][type] = 0;
        q.push(towns[i]);
        vis[towns[i]] = 1;
    }

    // find the min cost to reach all towns from towns of good type
    
    int costing = 1;
    while(!q.empty()){

        int qSize = q.size();

        while(qSize--){

            int node = q.front();
            q.pop();

            for(int x : adj[node]){
                if( vis[x] == 0){
                    vis[x]=1;
                    q.push(x);
                    cost[x][type] = costing;
                }
            }
        }
        costing ++;
    }
}

int main(){

    int n, m , k , s;
    cin >> n >> m >> k >> s;

    // type of goods present in each node

    vector<int> type(n+1);


    vector<vector<int>> townGoods(k+1);
    // 1 -> 
    // k ->
    // map associated to each type from 1 to k
    for(int i = 1; i <=n; i ++){
        // ith town, type of good associated to it
        cin >> type[i];
        townGoods[type[i]].push_back(i); 
        // all the towns selling the type : type[i]
    }

    // adjacency list storing n nodes and theri adjacet nodes
    vector<vector<int>> adj(n+1);

    for(int i = 0 ; i < m ; i++){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    vector<vector<int>> cost(n+1, vector<int> (k+1, INT_MAX));

    // cost[town][type ] : min cost required to reach from towni to a good j

    for(int i = 1; i <=k ;i++){
        // set of all towns which habe goods of type i
        vector<int> towns = townGoods[i];
        bfs(towns, i, cost, adj);
    }

    // fill in the table for cost[town][type]

    vector<long long> minCost(n+1, 0);

    for(int i = 1 ; i <= n; i++){

        vector<int> townWiseCost = cost[i];
        sort(townWiseCost.begin(), townWiseCost.end());

        long long ans = 0;
        for(int j = 0 ; j < s; j ++){
            ans += townWiseCost[j];
        }

        minCost[i] = ans;
        cout << ans << " ";
    }

    return 0;
}