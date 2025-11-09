#include<bits/stdc++.h>
using namespace std;

int leaf = 0;

void dfs(int curr, int parent, vector<int> &isCat, vector<vector<int>> &adj, int consecutiveCats, int m){
    if(isCat[curr] == 1 && isCat[parent]) consecutiveCats++;
    else if(isCat[curr] ==1) consecutiveCats = 1;
    else if(isCat[curr] == 0) consecutiveCats = 0;

    if(consecutiveCats > m){
        consecutiveCats--;
        return;
    } 

    for(int neighbour : adj[curr]){
        if(neighbour != parent) {
            dfs(neighbour, curr, isCat, adj,consecutiveCats, m);
        }
    }
    
    if(adj[curr].size() == 1 && adj[curr][0] == parent) leaf++;
    if(isCat[curr] == 1) consecutiveCats --;
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> isCat(n+1,0);

    // isCat[0] = 1;
    for(int i=1;i<=n;i++){
        cin >> isCat[i];
    }
    
    vector<vector<int>> adj(n+1);
    
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int consecutiveCats = 0;
    dfs(1,0,isCat, adj,consecutiveCats,m);

    cout << leaf << endl;
    return 0;
}