#include<bits/stdc++.h>
using namespace std;

vector<int> subset;

void dfs(int node, int parent, vector<vector<pair<int,int>>> &adj, vector<int>& isBadSubtree){

    for(auto children : adj[node]){
        int child = children.first;
        int badRoad = children.second;

        if(child != parent){
            if(badRoad == 2) {
                isBadSubtree[node] = 1;
            }
            dfs(child, node, adj, isBadSubtree);
            if(isBadSubtree[child]) isBadSubtree[node] = 1;
        }
    }
}

void findSubset(int node, int parent, vector<vector<pair<int,int>>> &adj, vector<int> & isBadTree){
    
    bool isNoChildBad = true;;
    for(auto x : adj[node]){
        int child = x.first;
        int badRoad = x.second;
        if( child != parent){
            if(isBadTree[child] || badRoad == 2){
                findSubset(child, node, adj, isBadTree);
                isNoChildBad = false;
            }
        }
    }

    if(isNoChildBad && node != 1) subset.push_back(node);
}

int main(){

    int n;
    cin >> n;

    vector<vector<pair<int,int>>> adj(n+1);

    for(int i = 0 ; i < n - 1; i++){
        int u, v , w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    // vectpr storign whether the subtree rooted at this node contains a bad road or not
    vector<int> isBadSubtree(n+1, 0);


    dfs(1, 0, adj, isBadSubtree);
    
    findSubset(1,0 , adj, isBadSubtree);

    cout << subset.size() << endl;
    for(auto it : subset){
        cout << it << " ";
    }
    cout << endl;
    return 0;
}