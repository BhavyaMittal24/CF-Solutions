#include<bits/stdc++.h>
using namespace std;

long long maxValue = 0;

void dfs(int node, int parent, vector<vector<int>> &adj, vector<int>& level, vector<long long> & subtree, vector<int> &value){

    if( parent != 0){
        level[node] = level[parent] + 1;
    }
    else {
        level[node] = 0;
    }

    subtree[node] = value[node];

    for(int x : adj[node]){
        if( x != parent){
            dfs(x, node, adj, level, subtree, value);
            subtree[node] += subtree[x];
        }
    }
}


void reroot(int node, int parent, vector<vector<int>> &adj, vector<long long> &ans, vector<long long> & subtree){

    maxValue = max(maxValue, ans[node]);

    for(int x : adj[node]){
        if( x != parent){

            subtree[node] -= subtree[x];
            ans[x] = ans[node] -subtree[x] + subtree[node]; 
            subtree[x] += subtree[node];
            reroot(x, node, adj, ans, subtree);

            subtree[x] -= subtree[node];
            ans[node] = ans[x] - subtree[node] + subtree[x];
            subtree[node] += subtree[x];
        }
    }
}

int main(){

    int n;
    cin >> n;
    vector<int> value(n+1, 0);

    for(int i = 1; i <= n ;i++){
        cin >> value[i];
    }


    vector<vector<int>> adj(n+1);
    
    for(int i = 0 ; i < n - 1 ; i ++){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<long long> subtree(n+1, 0);

    vector<int> level(n+1, 0);

    dfs(1,0, adj, level, subtree, value);
    long long firstAnswer  = 0;

    for(int i = 1; i <= n; i ++){
        firstAnswer +=  (1ll* value[i] * level[i] );
    }

    vector<long long> ans(n+1, 0);
    ans[1] = firstAnswer;

    //cout << firstAnswer << endl;
    reroot(1, 0, adj, ans, subtree);


    // for(int i = 1 ; i <= n ; i ++){
    //     cout << ans[i] << " ";
    // }
    cout << maxValue << endl;
    return 0;
}