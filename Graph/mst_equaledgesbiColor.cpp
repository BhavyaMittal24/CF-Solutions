#include<bits/stdc++.h>
using namespace std;

class DSU{

    public :
    int n;
    int cc;
    vector<int> rank;
    vector<int> parent;

    DSU(int n){
        this->n = n;
        rank.assign(n+1, 0);
        parent.assign(n+1, 0);

        cc = n;
        for(int i = 1; i <= n; i++) parent[i] = i;
    }

    int findSet(int u){
        if(u == parent[u]) return u;

        return parent[u] = findSet(parent[u]);
    }

    int getCC(){
        return cc;
    }

    void unionSet(int u, int v){
        u = findSet(u);
        v = findSet(v);
        // if both u and v belong to the same component
        if( u == v){
            return ;
        }

        if(rank[u] < rank[v]) swap(u,v);
        parent[v] = u;
        if(rank[u] == rank[v]) rank[u]++;
        cc--;
    }

};

int main(){

    int n, m;
    cin >> n >> m;
    // n nodes must nbe connected ot each other through a single path oly ; reachable nonly via a uniye path
    // all nodes must be connected ot ach other : mst

    // mp -> idx : to {u, v, S}
    map<int, vector<int>> edges;
    
    // storign the indices of edges for each type
    vector<int> type0;
    vector<int> type1;

    for(int i = 0; i < m; i ++){
        int u, v;
        char type;
        cin >> u >> v >> type;

        if( u == v) continue;
        // no need to have a cycle : we wont be clearnig it anyways as having 1-1->2
        // not a simple path anymore : pairwose distinct 
        if( type == 'M') {
            edges[i+1] = {u, v, 0};
            type0.push_back(i+1);
        }
        else {
            edges[i+1] = {u,v,1};
            type1.push_back(i+1); // index for the type1 edge
        }
    }

    // for n =1, no need to connect anything, we dont need to clear any road
    // 0 by type 1 and 0 by type2
    if( n == 1){
        cout << "0\n";
        return 0;
    }
    // when n is even , n-1 will be odd, we cant have equal edges of 0 amd 1 in the graph
    if( n % 2 == 0){
        cout << "-1\n";
        return 0;
    }

    if( type1.size() < (n-1)/2 || type0.size() < (n-1)/2 ) {
        cout << "-1\n";
        return 0;
    }

    // both have >= n-1/2 edges , npw ,erge thme in a way to connect all the components
    DSU dsu1(n); // hving n nodes from 1 to n

    for(auto idx : type0){
        vector<int> edgeInfo = edges[idx];
        int u = edgeInfo[0];
        int v = edgeInfo[1];
        dsu1.unionSet(u,v);
    }

    int cc = dsu1.cc;
    
    // required edges are cc - 1 to  connect cc components

    // no of edges required to connect all from type1 is cc-1 > n-1/2
    if( (cc - 1) > (n-1)/ 2){
        cout << "-1\n";
        return 0;
    }

    DSU dsu2(n);
    // add the edges from type1 in a way that to dsu1, they dont form a cycle and are <= n-1/2

    int i = 0;
    int cnt = 0;

    vector<int> ans;
    while( i < type1.size() && cnt < (n-1)/2 ){

        int idx = type1[i];
        vector<int> edgeInfo = edges[idx];
        int u = edgeInfo[0];
        int v = edgeInfo[1];
        if( dsu1.findSet(u) != dsu1.findSet(v)){
            // not connected
            ans.push_back(idx);
            // store the edges in dsu2 if later on cnt is not n-1/2 for type1 edges
            dsu2.unionSet(u,v);
            dsu1.unionSet(u,v);
            cnt++;
        }
        i++;
    }

    // cnt for type1 edges
    if( cnt < (n-1)/2) {
        // we need to make it n-1/2 for type1; connect those edges from type1 whcih dont form a cycle
    
        i = 0;

        while( i < type1.size() && cnt < (n-1)/2){
            int idx = type1[i];
            vector<int> edgeInfo = edges[idx];
            int u = edgeInfo[0];
            int v = edgeInfo[1];
            if( dsu2.findSet(u) != dsu2.findSet(v)){
                dsu2.unionSet(u,v);
                ans.push_back(idx);
                cnt++;
            }
            i++;
        }
    }
    // dsu2 has all data for edges from type1: such that they are n-1/2

    // put all the edges from ttpe0 such that total is n-1/2 and no of cc = 1 in dsu2
    // they should not be already connected

    i = 0;
    cnt = 0;
    while(i < type0.size() && cnt < (n-1)/2){

        int idx = type0[i];
        vector<int> edgeInfo = edges[idx];
        int u = edgeInfo[0];
        int v = edgeInfo[1];

        if( dsu2.findSet(u) != dsu2.findSet(v)){
            ans.push_back(idx);
            dsu2.unionSet(u,v);
            cnt++;
        }
        i++;
    }

    if( dsu2.cc != 1) {
        cout << "1\n";
        return 0;
    }

    cout << ans.size() << '\n';
    for(auto x : ans){
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}