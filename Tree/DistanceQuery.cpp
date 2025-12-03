#include<bits/stdc++.h>
using namespace std;

int m = 20;

void dfs( int curr, int parent, vector<vector<int>> &adj, vector<int> & level, vector<vector<int>> &parentPow){

    if( parent != 0) {
        level[curr] = level[parent]+1;
    }
    else level[curr] = 0;

    parentPow[curr][0] = parent;

    for(int i = 1; i < m ; i++){
        parentPow[curr][i] = parentPow [ parentPow[curr][i-1] ] [i-1];
    }

    for(int x : adj[curr]){
        if( x != parent){
            dfs(x, curr, adj,level, parentPow);
        }
    }
}


int findLCA ( int u, int v, vector<vector<int>> & parentPow, vector<int> & level ){

    if( u == v) {
        return u;
    }

    if( level[u] < level[v]){
        swap(u,v);
    }

    int diff = level[u] - level[v];


    for(int i = m-1 ; i >=0 ; i --){

        // ith bit is set 
        if ( (1 << i) & (diff) ) {
            u = parentPow[u][i];
        }
    }

    // they both are at the same level now

    if ( u == v) {
        return u;
    }
    // 20 + 21 ++... 2 i-1 <= 2 i
    for(int i = m-1 ; i >= 0 ; i -- ){
        // 2^ith parent is different
        if( parentPow[u][i] != parentPow[v][i]){
            u = parentPow[u][i];
            v = parentPow[v][i];
        }
    }

    // if u is at same level as v, they will stay the same : return u : 
    // else return the parent 
    return ( (u == v) ? u : parentPow[u][0]);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;    
    cin >> n >> q;


    vector<vector<int>> adj(n+1);

    for(int i = 0; i < n-1 ; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //vector<pair<int,int>> paths(m);

    // m is the no of bits : used to represent n : nth parent : as a power of 2

    vector<vector<int>> parentPow(n+1, vector<int> (m, 0));

    vector<int> level(n+1);
    dfs( 1, 0, adj, level, parentPow);

    for(int i = 0 ; i < q ; i++){
        int u, v;
        cin >> u >> v;

        int LCA = findLCA(u,v, parentPow, level);

        long long distance = 1ll*(level[u] + level[v]) - 2ll * level[LCA];
        cout << distance << endl;

    }

    return 0;

}