#include<bits/stdc++.h>
using namespace std;

// In a tree we have a unique parent for each node and one node has only one parent and there is only one way to reach a given node frpm any other given node
// for each node : [adj list and parent ] are it's adjacent neigbouring nodes

// No need for a visited array
vector<int> minDistanceFromNode(int src, vector<vector<int>> &adj){
    queue<pair<int,int>> q;
    q.push({src,0});
    int n = adj.size()-1;
    vector<int> dis(n+1,0);
    dis[src] = 0;
    while(!q.empty()){
        pair<int,int> top = q.front();
        int node = top.first;
        int parent =top.second;
        q.pop();

        for(int neighbour : adj[node]){
            if(neighbour != parent){
                q.push({neighbour,node});
                dis[neighbour] = dis[node]+1;
            }
        }
    }
    return dis;
}

// Find minDisrane from a node using without storing the parent in the queue.
// node -> child1 , cjild2, .. child n
// Dont want to add parent : so can use a vis array where if not visisted, only then push to queue

vector<int> minDisWithVis(int src, vector<vector<int>> & adj){
    int n = adj.size()-1;
    vector<int> vis(n+1,0);
    queue<int> q;
    q.push(src);

    vector<int> distance(n+1,0);
    distance[src] = 0;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        vis[node] = 1; 
        for(int neighbour : adj[node]){
            if(vis[neighbour] == 0){
                q.push(neighbour);
                distance[neighbour] = distance[node]+1;
            }
        }
    }
    return distance;
}

// IN REALITY, A TREE DOES NOT NEED A VISITED ARRAY BECAUSE A TREE HAS ONLY A SINGLE PATH BETWEEN ANY TWO NODES
// WHEN TRAVERSING, I CAN JUST HAVE THE INFORMATION OF THE ONLY PARENT AND ITS ADJACENT NODES AND THAT IS ENOUGH 
int main(){
    int n;
    // for a tree edges have to be n-1 : exactly for it to stay connected AND Acyclic
    cin >> n;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // find the distance from a node using bfs
    vector<int> dis = minDistanceFromNode(1,adj);
    dis = minDisWithVis(1,adj);
    for(int i=0;i<=n;i++){
        cout << dis[i] << " ";
    }
    return 0;
}