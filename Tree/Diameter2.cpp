#include<bits/stdc++.h>
using namespace std;

void dfsLeafNode(int curr, int parent, vector<vector<int>> &adj, vector<int>& maxLeafNodeDistance){
    maxLeafNodeDistance[curr] =  0;

    for(int neighbour : adj[curr]){
        if( neighbour != parent){
            dfsLeafNode(neighbour,curr, adj,maxLeafNodeDistance);
            maxLeafNodeDistance[curr] = max( maxLeafNodeDistance[curr], 1 + maxLeafNodeDistance[neighbour]);
        }
    }
}

void dfsMaxLCAPath(int curr, int parent, vector<vector<int>> &adj, vector<int> & maxLCAPath, vector<int> & maxLeafNodeDistance){
    maxLCAPath[curr] = 0;

    // array for max leaf node distances of neighbours : children 
    vector<int> neighbourLeafDistances;
    for(int neighbour : adj[curr]){
        neighbourLeafDistances.push_back(maxLeafNodeDistance[neighbour]);
    }

    // leaf node
    if(neighbourLeafDistances.size() == 0){
        maxLCAPath[curr] = 0;
    }
    else if( neighbourLeafDistances.size() == 1){
        maxLCAPath[curr] = 1 + neighbourLeafDistances[0];
    }

    else {
        sort(neighbourLeafDistances.begin(), neighbourLeafDistances.end());
        int n = neighbourLeafDistances.size();
        maxLCAPath[curr] = 2 + neighbourLeafDistances[n-1] + neighbourLeafDistances[n-2];
    }
}
int main(){

    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);

    // a tree has onyl n-1 edges : bec a unique oath exists between each node connecting them in a tree
    for(int i=0;i<n-1;i++){
        int u;
        int v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> maxLeafNodeDistance(n+1,0);
    vector<int> maxLCAPath(n+1,0);
    dfsLeafNode(1,-1,adj,maxLeafNodeDistance);
    dfsMaxLCAPath(1,-1,adj, maxLCAPath, maxLeafNodeDistance);
    
    int diamter = 0;
    for(int i=0;i<maxLCAPath.size();i++){
        diamter = max(diamter, maxLCAPath[i]);
    }

    cout << diamter << endl;
    return 0;

}