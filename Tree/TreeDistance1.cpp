#include<bits/stdc++.h>
using namespace std;

void dfs(int curr, int parent, vector<vector<int>> &adj, vector<int>& distance){
    if(parent == 0) distance[curr] = 0;
    else distance[curr] = distance[parent]+1;

    for(int neighbour : adj[curr]){
        if( neighbour != parent){
            dfs(neighbour, curr, adj, distance);
        }
    }
}

int findFarthestNode(vector<int> &distance){
    int fNode = 0;

    for(int i=1;i<distance.size();i++){
        if(distance[i] > distance[fNode]){
            fNode = i;
        }
    }
    return fNode;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> distanceX(n+1,0);
    dfs(1,0,adj,distanceX);

    int x = findFarthestNode(distanceX);

    vector<int> distanceY(n+1);
    dfs(x,0,adj,distanceY);

    int y = findFarthestNode(distanceY);

    vector<int> distanceZ(n+1);
    dfs(y,0,adj,distanceZ);
    vector<int> farthestNode(n);

    for(int i=0;i<n;i++){
        farthestNode[i] = max(distanceZ[i+1], distanceY[i+1]);
        cout << farthestNode[i] << " ";
    }
    return 0;
}