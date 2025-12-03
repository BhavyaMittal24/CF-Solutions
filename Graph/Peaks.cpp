#include<bits/stdc++.h>
using namespace std;

long long cnt = 0;

void dfs(int node, vector<int> &vis, vector<set<int>> &adj, vector<int> &heights){

    vis[node] = 1;

    bool isGood = true;
    for(int x : adj[node]){
        if( heights[node] <= heights[x]) isGood = false; 
    }

    if(isGood) cnt ++;

    for(int x : adj[node]){
        if( !vis[x]){
            dfs(x, vis, adj, heights);
        }
    }
}

int main(){

    int n, m;
    cin >> n >> m;

    vector<int> heights(n+1,0);

    for(int i = 1 ; i <= n ; i++){
        cin >> heights[i];
    }

    // i dont need duplicate edges : does not matter because still there will be one road to reach from i to j
    vector<set<int>> adj(n+1);

    for(int i = 0 ; i < m ; i++){
        int a, b;
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }


    vector<int> vis(n+1, 0);

    for(int i = 1 ; i <= n ; i++){
        if( vis[i] == 0){
            dfs(i, vis, adj, heights);
        }
    }

    cout << cnt << endl;
    return 0;
}