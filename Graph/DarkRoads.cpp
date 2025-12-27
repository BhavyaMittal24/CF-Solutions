#include<bits/stdc++.h>
using namespace std;

int main(){


    int n, m ;
    cin >> m >> n;

    while( n != 0 && m != 0){

        vector<vector<pair<int,int>>> adj(m);

        //m junctions : so for  each junction let's build the set of junctions it is connected to with the edge weight

        int totalCost = 0;
        for(int i = 0; i < n ; i ++){
            int u, v ,w;
            cin >> u >> v >> w;

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
            totalCost += w;
            // u --w -- > v connected to v with a weight w
        }

        vector<int> dist(m, INT_MAX);
        vector<int> vis(m, 0);

        // cost of  an edge leading to node u, u
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<> > pq;

        pq.push({0,0});
        // like dijsktra's algothm w have a distance array which represents the cost of any edge to the node u :
        // in disjtrla this was the cost to reach from source s to node u
        dist[0] = 0;

        int illuminationCost = 0;
        while( !pq.empty()){
            int edgeWt = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if( edgeWt > dist[node]) continue;

            // we need a visited array because we can have another minimum edge from the node u to a node which has alead ybeen visited and processed and just the distance check won;t be enough
            if( vis[node]) continue;

            // marking the node u as visited as it is now processed and we cqnt visit it again
            vis[node] = 1;

            illuminationCost += edgeWt;

            for( auto x : adj[node]){
                int v = x.first;
                int w = x.second;

                // it might be that distance[v] > weight for the edge, but that edge could have been already visited or processed before
                //   dist[1] = 6:  1 ----4------>  2 : so from 2,  I can go back to 1 using the edgeWeight 4 as (4 < dist[1])  
                if( w < dist[v] && vis[v] == 0){
                    pq.push({w,v});
                    dist[v] = w;
                }
            }
        }
        
        totalCost -= illuminationCost;
        cout << totalCost << endl;
        cin >> m >> n;
    }

    return 0;
}