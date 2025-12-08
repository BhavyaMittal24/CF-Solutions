#include<bits/stdc++.h>
using namespace std;

class DSU{

    public :
    vector<int> parent, size;

    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1,1);

        size[0] = 0;
        for(int i = 1 ;i <= n ; i ++){
            parent[i] = i;
        }
    }

    // log(n) on an average 
    int findSet(int x){
        if( x == parent[x]) return x;

        return parent[x] = findSet(parent[x]);
    }

    void unionSet(int a, int b){
        a = findSet(a);
        b = findSet(b);

        // a and b both belong to the same component
        if( a == b ){
            return;
        }
        if( size[a] < size[b]){
            swap(a,b);
        }
        parent[b] = a;
        size[a] += size[b];
    }
};



int main(){

   freopen("closing.in", "r", stdin);
   freopen("closing.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);

    for(int i = 0 ; i < m ; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    
    // permutation of nodesin which the yare removed
    vector<int> permut(n);

    for(int i = 0 ; i < n; i ++){
        cin >> permut[i];
    }

    vector<int> vis(n+1,0);

    vector<string> response;
    DSU dsu(n);

    int cntOfNodesSoFar = 0;
    int lastNode = -1;

    for(int i = n-1; i >= 0 ;i--){
        
        int node = permut[i];

        if( i <= n-2) {

            int parentLastNode = dsu.findSet(lastNode);
            if(dsu.size[parentLastNode] == cntOfNodesSoFar){
                response.push_back("YES");
            }
            else{
                response.push_back("NO");
            }
        }

        vis[node] = 1;
        cntOfNodesSoFar ++;

        for(int x : adj[node]){
            if( vis[x]){
                dsu.unionSet(node,x);
            }
        }
        lastNode = node;
    }

    int parentLastNode = dsu.findSet(lastNode);

    if(dsu.size[parentLastNode] == cntOfNodesSoFar){
        response.push_back("YES");
    }
    else{
        response.push_back("NO");
    }

    for(int i = n-1 ; i >= 0 ; i--){
        cout << response[i] << '\n';
    }
    return 0;
}