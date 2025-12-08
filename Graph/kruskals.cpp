#include<bits/stdc++.h>
using namespace std;

bool static comp( vector<int> &a, vector<int> &b){
    return a[2] < b[2];
}

vector<int> parent;
vector<int> Rank;

int findSet(int x){
    if( x == parent[x]) {
        return x;
    }
    return parent[x] = findSet(parent[x]);
}

void unionSet(int a, int b){
    a = findSet(a);
    b = findSet(b);

    // dont belong to the same cc
    if( a != b){
        if(Rank[a] < Rank[b]){
            swap(a,b);
        }
        parent[b] = a;

        if(Rank[a] == Rank[b]){
            Rank[a]++;
        }
    }
}

bool isSameComponent( int a, int b){
    return findSet(a) == findSet(b);
}

// WHat is a MST : Minimum spanning tree
// Spanning Tree is a subgraph where all nodes are present but there is no cycle
// A min spanning tree is that spanning tree where the sum of all edges is minimun : n-1 edges are onyl there but nodes are m
// ALgorithm to find the MST : pickup the smallest edges : sort them acc to edge weight and then use the DSU 
// DSU to make a tree like structure : where you can't make another edge again and again
// if the nodes are not connected, make an edge between them and add to the weight : otherwise if they are already connected, :
// no need to consider that edge weight and skip it\

// Tc : 0(mlogm + m* alpha(n))

int main(){

    int n, m;
    cin >> n >> m;

    parent.resize(n+1,0);

    Rank = vector<int>(n+1,0);

    for(int i = 1 ;i <= n ; i++){
        parent[i] = i;
    }

    // implementing a DSU
    vector<vector<int>> edges(m);

    for(int i = 0; i < m ;i ++){
        int u,v,w;
        cin >> u >> v >> w;
        edges[i] ={u,v,w}; 
    }

    sort(edges.begin(), edges.end(), comp);

    vector<vector<int>> ans;

    long long mst = 0;
    for(int i = 0; i < m; i ++){
        vector<int> edge = edges[i];
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        if( isSameComponent(u,v)){
            continue;
        }

        unionSet(u,v);
        mst += w;
        ans.push_back({u,v,w});
        cout << u << " " << v << " " << w << endl;
    }

    cout << "FInal weight is " << mst << endl;
    return 0;
}