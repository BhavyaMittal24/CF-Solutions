#include<bits/stdc++.h>
using namespace std;


void dfs(int curr, int parent, vector<long long> &treeSize, vector<int> &containsX, vector<vector<int>> &adj, int x){
    treeSize[curr] = 1;
    if(curr == x) {
        containsX[curr]  =1;
    }

    for(int neighbour : adj[curr]){
        if( neighbour != parent){
            dfs(neighbour, curr, treeSize, containsX, adj, x);
            treeSize[curr] += treeSize[neighbour];
            containsX[curr] = containsX[curr] || containsX[neighbour];
        }
    }
    return;
}
int main(){

    int n,x,y;
    cin >> n >> x >> y;

    vector<vector<int>> adj(n+1);

    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<long long> treeSize(n+1,0);
    // y is the root : rooted at Y
    // find the node which contains x
    
    vector<int> containsX(n+1,0);

    dfs(y,0, treeSize, containsX, adj, x);

    int z = 0;


    for(int children : adj[y]){
        if(containsX[children] == 1){
            z = children;
        }
    }

    // cout << treeSize[x] << " " << treeSize[y] << " " << z << " " << treeSize[z] << endl;
    long long ans = 1ll* n *(n-1);

    long long badWays = 1ll*treeSize[x] * (n - 1ll*treeSize[z]);

    ans = ans - badWays;
    cout <<  ans << endl;
}