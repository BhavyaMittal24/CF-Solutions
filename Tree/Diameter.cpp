#include<bits/stdc++.h>
using namespace std;


// find thr diamter of a tree
// pick a node, find the maximum distance of a any node from this node. let the node farthest be called as Y
// from Y, find the farthest node Z

// vector<int> maxDist() : -> maxDistance of node i from the node X : (root)
void dfs(int curr, int parent, vector<int> &maxDist, vector<vector<int>> adj){
    if(parent == -1) maxDist[curr] = 0;
    else maxDist[curr] = maxDist[parent] +1;

    for(int neighbour : adj[curr]){
        if( parent != neighbour){
            dfs(neighbour, curr, maxDist, adj);
        }
    }
}

int findFarthestNode(vector<int> maxDist){
    int y = 0;
    for(int i=0;i<maxDist.size();i++){
        if(maxDist[y] < maxDist[i]){
            y = i;
        }
    }
    return y;
}

int main(){

    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<n-1;i++){
        int u;
        int v;
        cin >> u;
        cin >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> maxDistX(n+1,0);
    dfs(3,-1,maxDistX, adj);

    int Y = findFarthestNode(maxDistX);

    vector<int> maxDistY(n+1,0);
    dfs(Y, -1,maxDistY, adj);

    int Z = findFarthestNode(maxDistY);

    cout << Y << Z << endl;
    cout << maxDistY[Z] << endl;
    return 0;
}