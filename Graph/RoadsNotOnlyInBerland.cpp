/*
    UNdirected connected graph : MST
    This is also unweighted graph : No weight between the edges : Span the graph such that the maximum degree of any vertex is maximum out og all possible spanning tress

*/

#include<bits/stdc++.h>
using namespace std;


// Implementing Disjoint Set union

vector<int> parent;
vector<int> Rank;

int findSet(int x){

    if(x == parent[x]) return x;
    // path compression
    return parent[x] = findSet(parent[x]);
}

void unionSet(int u, int v){

    u = findSet(u);
    v = findSet(v);

    if( u != v){

        if(Rank[u] < Rank[v]){
            swap(u,v);
        }
        // rank[u] >= rank[v];
        parent[v] = u;
        if(Rank[u] == Rank[v]){
            Rank[u]++;
        }
    }
}

bool isSameComponent(int u, int v){

    return findSet(u) == findSet(v);
}


int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
 
    // n nodes, m edges
    // using DSU
    // 0(1) adding edge : m edges : 0(m)
    
    vector<vector<int>> adj(n+1);

     // u -> v 
    parent.assign(n+1, 0);
    Rank.assign(n+1, 0);

    for(int i = 0; i <= n; i++) parent[i] = i;

    vector<pair<int,int>> edges; // pair of spare edges

    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
    
        if(isSameComponent(u,v)) {
            // we will not add this edge
            edges.push_back({u,v});
            // adding these edges as u and v are realdty connected as they belong to the same component
            // have same set
            continue;
        }

        unionSet(u,v);
    }

    // x spare edges : x + 1 components will be there
    vector<int> spareComponents;

    for(int i = 1; i <= n; i ++){
        if(parent[i] == i) {
            spareComponents.push_back(i);
        } 
    }

   cout << edges.size() << "\n";
    int prev = spareComponents[0];

    for(int i = 1; i < spareComponents.size(); i ++){
        int oldU = edges[i-1].first;
        int oldV = edges[i-1].second;

        int newU = prev;
        int newV = spareComponents[i];
        cout << oldU << " " << oldV << " " << newU << " " << newV << "\n";
    }
    
    return 0;
}