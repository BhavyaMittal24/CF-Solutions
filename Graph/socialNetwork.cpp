#include<bits/stdc++.h>
using namespace std;

// instrad of mainitainig a class, use DSU DIsjoint set Union component outside

vector<int> parent;
vector<int> sz;

// sz , parent[node]
// unique pairs : map< sz[parnet[node]], parent[node]>
set<pair<int,int>> ms;


int findSet(int x){
    // x is itself a parent of x : rooy
    if( x == parent[x]){
        return x;
    }

    return parent[x] = findSet(parent[x]);
}

bool isSameComponent(int a, int b){
    return findSet(a) == findSet(b);
}

void unionSet(int a, int b){
    a = findSet(a);
    b = findSet(b);
    if( a == b){
        return;
    }

    if(sz[a] < sz[b]){
        swap(a,b);
    }
    // b -> a

    ms.erase({sz[a], a});
    ms.erase({sz[b], b});
    sz[a] += sz[b];
    parent[b] = a;
    ms.insert({sz[a], a});
}

int main(){

    int n, d;
    cin >> n >> d;

    parent.resize(n+1,0);
    sz.resize(n+1,1);

    for(int i = 1 ; i <= n ; i ++){
        parent[i] = i;
    }

    // ms <sz[parent[u]], parent[u]

    // sz for the node, parent of the node
    for(int i = 1 ; i <= n ; i++){
        ms.insert({sz[i], parent[i]});
    }

    vector<int> maxAc;
    int extraEdges = 0;
    for(int i = 0 ; i < d ; i++){
        int u, v;
        cin >> u >> v;

        if(isSameComponent(u,v)){
            extraEdges ++;
        }
        else {
            unionSet(u,v);
        }

        int ans = 0;
        // take the value for the 
        int temp = extraEdges+1;
        auto it = ms.rbegin();
        
        // i + logn
        while( temp && it != ms.rend()){
            ans += it->first;
            it++;
            temp--;
        }

        maxAc.push_back(ans-1);
    }
    // tc : 0( d * (logn + n))

    for(int i = 0 ; i < d ; i ++){
        cout << maxAc[i] << endl;
    }
    return 0;
}