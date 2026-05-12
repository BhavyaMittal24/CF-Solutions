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
    int m;
    cin >> m;
    // n nodes, m edges
    // using DSU
    // 0(1) adding edge : m edges : 0(m)
    
    vector<vector<int>> adj(n+1);

    vector<pair<int,int>> edges(m);
    int maxDegreeVertex = 0;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);

        edges[i] = {u,v};
        if( adj[u].size() > adj[maxDegreeVertex].size()){
            maxDegreeVertex = u;
        }

        if(adj[v].size() > adj[maxDegreeVertex].size()){
            maxDegreeVertex = v;
        }
    }

    // u -> v 
    parent.assign(n+1, 0);
    Rank.assign(n+1, 0);

    for(int i = 0; i <= n; i++) parent[i] = i;
    // 1 -> 1, 2- > 2 , 

    vector<pair<int,int>> ans;
    for(int x : adj[maxDegreeVertex]){
        // connecting all edges from maxDegree vertex
        unionSet(maxDegreeVertex, x);
        ans.push_back({maxDegreeVertex, x});
    }


    for(int i = 0 ; i < m; i ++){
        int u = edges[i].first;
        int v = edges[i].second;
        // this means the y are already connected : goal is to make all of them belong under one parent
        if(isSameComponent(u,v)) continue;

        unionSet(u,v);
        // include this edge as his makes two disjoint components together join intp one big component
        ans.push_back({u,v});
    }

    for(auto it : ans){
        cout << it.first << " " << it.second << "\n";
    }
    
    return 0;
}