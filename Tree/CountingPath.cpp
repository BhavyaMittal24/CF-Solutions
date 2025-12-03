#include<bits/stdc++.h>
using namespace std;

int maxN  = 2e5+1;

vector<int> countNodeFreq(maxN);

void dfs( int curr, int parent, int terminalNode, vector<vector<int>> &adj, vector<int> &pathTaken){

    pathTaken.push_back(curr);

    if(curr == terminalNode){
        for(int node: pathTaken){
            countNodeFreq[node]++;
        }
        return;
    }

    for(int x : adj[curr]){
        if( x != parent){
            dfs(x, curr, terminalNode, adj, pathTaken);
        }
    }

    pathTaken.pop_back();
}

int main(){

    int n, m;    
    cin >> n >> m;


    vector<vector<int>> adj(n+1);

    for(int i = 0; i < n-1 ; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //vector<pair<int,int>> paths(m);

    for(int i = 0 ; i < m ; i++){
        int a, b;
        cin >> a >> b;
        vector<int> pathTaken;
        dfs(a,0,b,adj, pathTaken);
    }

    for(int i = 1; i <= n ; i ++){
        cout << countNodeFreq[i] << " ";
    }

    return 0;

}