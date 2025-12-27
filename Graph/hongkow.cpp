#include<bits/stdc++.h>
using namespace std;


vector<int> parent;

vector<int> sz;

vector<int> edgeCount;

vector<int> disjoint;

set<pair<int,int>> st;
int findSet(int x){

    if (x == parent[x]) return x;
    return parent[x] = findSet(parent[x]);
}


bool isSameComponent(int a, int b){
    return findSet(a) == findSet(b);
}

void unionSet(int a, int b){

    a = findSet(a);
    b = findSet(b);

    if( a == b) {
        edgeCount[a] ++;
        return;
    }

    if( disjoint[a]){
        parent[b] = a;
        sz[a]  += sz[b];
        edgeCount[a] += (edgeCount[b] +1);
        return;
    }

    else if( disjoint[b] ){
        parent[a] = b;
        sz[b]  += sz[a];
        edgeCount[b] += (edgeCount[a] +1);
        return;
    }

    else if( a != b){
        if( sz[a] < sz[b]){
            swap(a,b);
        }

        parent[b] = a;
        sz[a] += sz[b];
        edgeCount[a]  = edgeCount[a] + edgeCount[b] +1;
    }
}


int main(){


    int n, m ,k;
    cin >> n >> m >> k;

    parent.resize(n+1,0);
    sz.resize(n+1, 1);
    edgeCount.resize(n+1,0);

    disjoint.resize(n+1, 0);

    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    for(int i = 0; i < k ; i++){
        int country;
        cin >> country;
        disjoint[country] = 1;
    }


    for(int i = 0 ; i < m ;i ++){
        int u, v;
        cin >> u >> v;
        if(st.find({u,v}) != st.end() ) continue;
        if(st.find({v,u}) != st.end() ) continue;
        unionSet(u,v);
    }


    int disjointNode = 0;

    int extraEdges = 0;

    int extraNodes = 0;
    for(int i = 1 ; i <= n ; i++){

        //cout << sz[i] << endl;
        if(disjoint[i] == 1) {

            if( sz[disjointNode] < sz[i]){
                disjointNode = i;
            }
            //disjointNodeMaxEdges  = max(disjointNodeMaxEdges, edgeCount[i]);
        }

        else {

            int root = findSet(i);
            if( disjoint[root] == 1) continue;
            extraNodes ++;
            if(parent[i] == i){
                extraEdges += edgeCount[i];
            }
        }
    }

    //cout << disjointNode << " " << sz[disjointNode] << " " << extraNodes << " " << extraEdges << endl;
    extraNodes += sz[disjointNode];

    long long ans = 1ll*extraNodes * (extraNodes -1);
    ans = ans/2;

    ans  = ans - (extraEdges + edgeCount[disjointNode]);

    cout << ans << endl;

    return 0;
}