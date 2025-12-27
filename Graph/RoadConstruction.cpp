#include<bits/stdc++.h>
using namespace std;

vector<int> parent;

vector<int> size;


int cc = 0;

int maxComponentSize = 1;

int findSet(int x){
    if( x == parent[x] ) return x;
    return parent[x] = findSet(parent[x]);
}

void unionSet(int a, int b){
    a = findSet(a);
    b = findSet(b);

    if( a != b){
        if(size[a] < size[b]){
            swap(a, b);
        }
        parent[b] = a;
        size[a] += size[b];
        maxComponentSize = max(maxComponentSize, size[a]);
        cc--;
    }
}

bool isSameComponent(int u, int v){
    return findSet(u) == findSet(v);
}

int main(){

    int n, m;
    cin >> n >> m;

    cc = n;
    parent.resize(n+1,0);
    size.resize(n+1, 1);

    vector<pair<int,int>> response;

    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    for(int i = 0 ; i < m ; i++){
        int u, v;
        cin >> u >> v;

        if( !isSameComponent(u,v)) unionSet(u, v);

        response.push_back({cc,maxComponentSize});
    }

    for(int i = 0 ; i < m ; i ++){
        cout << response[i].first << " " << response[i].second << endl;
    }
    return 0;
}