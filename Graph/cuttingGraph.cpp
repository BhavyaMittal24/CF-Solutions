#include<bits/stdc++.h>
using namespace std;

vector<int> parent, Rank;

int findSet(int x){

    if( x == parent[x]) return x;
    return parent[x] = findSet(parent[x]);
}

bool isSame(int a, int b){
    return findSet(a) == findSet(b);
}

void unionSet(int a, int b){
    a = findSet(a);
    b = findSet(b);
    if( a != b){
        if( Rank[a] < Rank[b]) swap(a,b);
        parent[b] = a;

        if(Rank[a] == Rank[b]) Rank[a] ++;
    }
}

int main(){
    int n, m, k;
    cin >> n >> m >> k;

    parent.resize(n+1, 0);

    Rank.resize(n+1, 0);

    for(int i = 1; i <=n ;i ++){
        parent[i] = i;
    }
    vector<set<int>> adj(n+1);

    for(int i = 0; i < m ; i++){
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    vector<pair<string, pair<int,int>>> queries(k);
    for(int i = 0 ; i < k ; i ++){
        string s;
        int u, v;
        cin >> s;
        cin >> u >> v;
        queries[i] = {s, {u ,v}};
    }

    vector<string> response;

    vector<int> vis(n+1,0);
    for(int i = k-1; i >=0; i--){
        auto query = queries[i];
        int u = query.second.first;
        int v = query.second.second;
        string op = query.first;
        if(op == "cut" ){   
            unionSet(u,v);
        }

        else{
            if(isSame(u,v)){
                response.push_back("YES");
            }
            else response.push_back("NO");
        }
    }

    for( int i = response.size() - 1; i >= 0 ; i--){
        cout << response[i] << endl;
    }

    return 0;
}