#include<bits/stdc++.h>
using namespace std;

class DSU{

    int n;

    vector<int> parent;
    vector<int> rank;

    public : 
    DSU(int n){
        this->n = n;
        parent.assign(n+1, 0);
        rank.assign(n+1, 0);
        for(int i =1; i <= n; i ++){
            parent[i] = i;
        }
    }

    int findSet(int x){
        if( x == parent[x]) return x;
        
        return parent[x] = findSet(parent[x]);
    }

    bool isConnected(int u, int v){
        return findSet(u) == findSet(v);
        // if u and v both belong to the same connected component o not
    }

    void unionSet(int u, int v){
        u = findSet(u);
        v = findSet(v);

        if( u != v){

            if(rank[u] < rank[v]) swap(u,v);
            // rank u is bigger : v is taken inside u
            parent[v] = u;
            if(rank[u] == rank[v]){
                rank[u]++;
            }
        }
    }
};

void solve(){

    int n, m1, m2;
    // m1 fpr graph F
    // m2 for graph G
    cin >> n >> m1 >> m2;

    vector<pair<int,int>> Fedges(m1);
    vector<pair<int,int>> Gedges(m2);

    DSU dsuF(n);
    DSU dsuG(n);
    for(int i = 0; i < m1; i ++){
        int u, v;
        cin >> u >> v;
        Fedges[i] = {u,v};
    }

    for(int i = 0;i < m2; i ++){
        int u, v;
        cin >> u >> v;
        Gedges[i] = {u,v};
        dsuG.unionSet(u,v);
    }

    int remove = 0;

    for(int i = 0; i < m1; i ++){
        pair<int,int> edge = Fedges[i];
        int u = edge.first;
        int v = edge.second;

        // find set if the parents are same for both u, v in G : there is a path from u to v in G
        if(dsuG.isConnected(u,v)){
            dsuF.unionSet(u,v);
        }

        else{
            // not connected in G, but in f they are
            remove++;
        }
    }

    // found the connected components in F which are also connected in G, but still a subset

    int add = 0;
    for(int i = 0; i < m2; i ++){
        auto edge = Gedges[i];
        int u = edge.first;
        int v= edge.second;

        if(dsuF.isConnected(u,v)){
            continue;
        }
        else {
            add++;
            dsuF.unionSet(u,v);
        }
    }

    int ans = add + remove;
    cout << ans << '\n';
    return;
}
int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}