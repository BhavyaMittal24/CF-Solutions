#include<bits/stdc++.h>
using namespace std;


bool comp( pair<int,int> &a, pair<int,int> &b){
    return a.second < b.second;
}

int main(){

    int n;
    cin >> n;

    // minumum money to build roads to connect every pair of nodes
    // {xi, yi} -> i;

    vector<vector<pair<int,int>>> adj(n);
    map<pair<int,int> , int> mp;
    vector<pair<int,int>> nodesX(n);
    vector<pair<int,int>> nodesY(n);

    for(int i = 0; i < n ; i ++){
        int xi, yi;
        cin >> xi >> yi;
        nodesX[i] = {xi, i};
        nodesY[i] = {yi, i};
    }

    sort(nodesX.begin(), nodesX.end());
    sort(nodesY.begin(), nodesY.end());

    long long minCost = 0;

    for(int i = 1 ; i < n ; i++){
        int wt = nodesX[i].first - nodesX[i-1].first;
        wt = abs(wt);
        int firstNode = nodesX[i].second;
        int secondNode = nodesX[i-1].second;
        adj[firstNode].push_back({secondNode, wt});
        adj[secondNode].push_back({firstNode, wt});

        firstNode = nodesY[i].second;
        secondNode = nodesY[i-1].second;
        int wty = nodesY[i].first - nodesY[i-1].first;
        wty = abs(wty);
        adj[firstNode].push_back({secondNode, wty});
        adj[secondNode].push_back({firstNode, wty});
    }

    vector<int> vis(n,0);
    vector<int> cost(n, INT_MAX);

    // we use a min heap
    // {dist, node}
    priority_queue< pair<int, int>, vector<pair<int,int>> , greater<> > pq;
    pq.push({0,0});
    cost[0] = 0;

    while( !pq.empty()){

        int edgeWt = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        if( edgeWt > cost[node]) continue;

        if( vis[node]) continue;

        minCost += edgeWt;
        vis[node] = 1;

        for(auto x : adj[node]){
            int v = x.first;
            int w = x.second;

            if( cost[v] > w && vis[v] == 0){
                cost[v] = w;
                pq.push({w, v});
            }
        }
    }

    cout << minCost << endl;
    return 0;
}