#include<bits/stdc++.h>
using namespace std;

void dfs(int curr, int parent, vector<vector<int>>& adj, vector<int> &disrespectfulNodes, vector<int> &c){
    bool isCurrNodeDisrespectful = (c[curr] == 0) ? false : true;

    for(int neighbour : adj[curr]){
        if( neighbour != parent){
            dfs(neighbour, curr, adj, disrespectfulNodes, c);
            isCurrNodeDisrespectful = isCurrNodeDisrespectful && (c[neighbour] == 1);
        }
    }
    if(isCurrNodeDisrespectful) disrespectfulNodes.push_back(curr);
}

int main(){
    int n;
    cin >> n;
    vector<int> c(n+1);
    vector<vector<int>> adj(n+1);
    vector<int> parent(n+1);
    
    int root;
    for(int i=1;i<=n;i++){
        int pi,ci;
        cin >> pi >> c[i];
        if(pi == -1) {
            parent[i] = 0;
            root = i;
        }
        else {
            parent[i] = pi;
            adj[parent[i]].push_back(i);
            adj[i].push_back(parent[i]);
        }
    }

    vector<int> disrespectfulNodes;
    dfs(root, 0, adj, disrespectfulNodes, c);

    sort(disrespectfulNodes.begin(), disrespectfulNodes.end());
    if(disrespectfulNodes.size() == 0) cout << -1 << endl;
    for(int i : disrespectfulNodes) cout << i << " ";

    return 0;

}