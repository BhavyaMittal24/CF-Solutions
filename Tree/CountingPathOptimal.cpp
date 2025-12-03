#include<bits/stdc++.h>
using namespace std;

void setPrefix(int curr, int parent, vector<vector<int>> &adj, vector<int> & ans){

    for(int x : adj[curr]){
        
        if( x != parent){
            setPrefix(x, curr, adj, ans);
            ans[curr] += ans[x];
        }
    }
}

void dfs( int curr, int parent, vector<vector<int>> & adj, vector<vector<int>> & parentsPow,  vector<int> & level){
    if( parent == 0){
        level[curr] = 0;
    }
    else level[curr] = level[parent]+1;

    parentsPow[curr][0] = parent;

    int m = parentsPow[0].size();

    for(int i = 1 ;i< m ;i ++){
        parentsPow[curr][i] =  parentsPow [ parentsPow[curr][i-1]] [i-1];
    }

    for( int x : adj[curr]){
        if( x != parent){
            dfs( x, curr, adj, parentsPow, level);
        }
    }
}   

int findLCA( int u, int v, vector<int> &level, vector<vector<int>> & parentsPow){
    if ( u == v){
        return u;
    }

    if(level[u] < level[v]){
        swap(u,v);
    }

    int diff = level[u] - level[v];

    int m = parentsPow[0].size();

    for( int i = 0 ; i < m ; i ++){
        if( (1 << i) & diff ){
            u = parentsPow[u][i];
        }
    }

    if ( u == v) {
        return u;
    }

    // at the same level

    for(int i = m-1 ; i >= 0 ; i --){
        if( parentsPow[u][i] != parentsPow[v][i] ){
            u = parentsPow[u][i];
            v = parentsPow[v][i];
        }
    }

    return (u == v ) ? u : parentsPow[u][0];
}

int main(){

    int n, q;
    cin >> n >> q; 

    vector<vector<int>> adj(n+1);

    for( int i = 0; i < n-1 ; i++){
        int u, v;

        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // store the parents in powers of 2

    int m = log2(n)+1;

    // 16 : 5 powers : I need to store ,0, 1, 2, 3 , 4
    // 1 based indexing
    vector<vector<int>> parentsPow(n+1, vector<int> (m,0));
    vector<int> level(n+1, 0);
    vector<int> ans(n+1, 0);

    dfs( 1, 0 , adj, parentsPow, level);

    for(int i = 0; i < q ; i ++){
        int a, b;
        cin >> a >> b;
        int lca = findLCA(a, b, level, parentsPow);
        //cout << a << " " << b << " " << lca << endl;
        ans[a]++;
        ans[b]++;
        if( lca != 0) ans[lca]--;

        int lcaParent = parentsPow[lca][0];
        if(lcaParent != 0) ans[lcaParent] --;
    }

    // now make the prefix sum to have the actual difference array

    // for(int i = 0 ; i <=n ;i ++){
    //     cout << ans[i] << ' ';
    // }
    // cout << endl;
    setPrefix(1, 0 , adj, ans);

    for(int i = 1 ; i <= n ; i++){
        cout << ans[i] << " "; 
    }
    return 0;
    
}