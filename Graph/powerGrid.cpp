#include<bits/stdc++.h>
using namespace std;


int main(){

    int n;
    cin >> n;
    vector<pair<int,int>> coordinates(n+1);
    for(int i = 1 ; i <= n ; i++){
        int x, y;
        cin >> x >> y;
        coordinates[i] = {x, y};
    }

    vector<int> soloCost(n+1,0);
    vector<int> connectingCost(n+1,0);

    int minCostNode = 1;
    for(int i = 1 ; i <= n; i ++){
        
        cin >> soloCost[i];
        if(soloCost[minCostNode] > soloCost[i]){
            minCostNode = i;
        }
    }

    for(int i = 1 ; i <= n ;i ++){
        cin >> connectingCost[i];
    }

    vector<int> powerGrid;
    vector<pair<int,int>> edges;

    vector<int> vis(n+1,0);
    // connect the edges in such a way or give power grid to a node so that the total cost of setting up the graph is minimim

    // {wt, u, v}
    // for nodes where I am adding the power plant diredtly, the value for u is -1 and w is cv : u-> v

    priority_queue< pair<long long, pair<int,int>> , vector< pair<long long, pair<int,int>>> , greater<> > pq;

    long long totalCost = 0;

    vector<long long> distance(n+1, 1e18);
    

    for(int i = 1; i <= n ; i++){
        pq.push({ soloCost[i], {-1,i}});
        distance[i] = soloCost[i];
    }
    // mark this distance as relaxed and minimum : serves like a visited array

     while( !pq.empty()){

        auto topEdge = pq.top();
        pq.pop();

        long long nodeCost = topEdge.first;
        int u = topEdge.second.first;
        int v = topEdge.second.second;

        if( distance[v] < nodeCost) continue;

        if( vis[v] == 1) continue;
        // we can connect the edge from u to v or have v directly as a node
        // if there is some edge and I have minimum cost to reach directly or setup plant then use that option
        
        // If we are coming from u (not -1) or we are comign from -1

        // solocost[v] is the least cost possible so we push the node to the3 power grid
        if( u == -1){
            powerGrid.push_back(v);
        }
        // u,v and nodeCost <= soloCOst[v]
        else {
            edges.push_back({u,v});
        }

        totalCost += nodeCost;
        vis[v] = 1;

        // u, v : at edge v reached from u
        for(int i = 1; i <= n ; i ++){

            if( vis[i]) continue; 
            long long costToConnect = 1ll*(connectingCost[v] + connectingCost[i] );
            auto p1 = coordinates[v];
            auto p2= coordinates[i];

            long long d = abs(p1.first - p2.first) + abs(p1.second - p2.second);
            
            costToConnect *= d;

            if( distance[i] > costToConnect){
                distance[i] = costToConnect;
                pq.push({costToConnect, {v, i}});
            }   
        }

    }

    
    cout << totalCost << endl;
    cout << powerGrid.size() << endl;
    for(int i = 0 ; i < powerGrid.size() ; i++){
        cout << powerGrid[i] << " ";
    }
    cout << endl;

    cout << edges.size() << endl;
    for(int i = 0 ; i < edges.size(); i ++){
        cout << edges[i].first << " " << edges[i].second << endl;
    }

    return 0;
}