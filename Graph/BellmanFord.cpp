#include<bits/stdc++.h>
using namespace std;

/*
DIRECTED GRAPH 
Negative edges and negative cycle can exists : detects it
After k iterations of relaxations, I can find the min /shortest path from src to all nodes where the distance is <= k edges
// 1st iteration : 
*/
class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        // for a negative edge in an undirected graph, the distance from src to it will be -infiintiy
        // there will be too many edges in between src to node i
        // src ----a -ve b--- : infinite edges no clear payhe exst
        // for a directed graph, we want to see, even if a negative cycle exists
        // some nodes my be reachable before anegative cycle comes up from a source, e can find the answer for them
        // the nodes which are reachable from the negative cycle will have -INF as distance
        // infinte negativ eedges
        
        // one iteration is relaxation of all edges
        
        vector<int> dist(V, 1e8);
        dist[src] = 0;
        // relax the edges V-1 time, so in each iteration the ith+1 node shortest distance can bwe found
        for(int i = 0; i < V-1; i ++){
            
            for(int j = 0; j < edges.size(); j ++){
                vector<int> edge = edges[j];
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                if(dist[u] != 1e8 && dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                }
            }
        }
        // at the Vth iteration, when we have dome V-1 iteation, all paths should be found
        // for all nodes havi
        bool relax = false;
        for(int j = 0; j < edges.size(); j ++){
            
            vector<int> edge = edges[j];
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if(dist[u] != 1e8 && dist[v] > dist[u] + w){
                // dist[v] = dist[u] + w;
                relax = true;
            }
        }
        
        if(relax) {
            return {-1};
        }
        return dist;
    }
    /*
    8
4
1 0 -4
3 5 -4
4 3 -5
5 3 -10
1
*/
};
