#include <bits/stdc++.h>
using namespace std;

class DSU
{
    public: 
    vector<int> parent, Rank;

    DSU(int n){
        parent.resize(n+1, 0);
        Rank.resize(n+1, 0);
        for( int i = 1 ; i <= n ; i++){
            parent[i] = i;
        }
    }

    int findSet(int x)
    {
        if (x == parent[x])
            return x;
        return parent[x] = findSet(parent[x]);
    }

    void unionSet(int a, int b)
    {
        a = findSet(a);
        b = findSet(b);

        if (a != b)
        {
            if (Rank[a] < Rank[b])
            {
                swap(a, b);
            }
            // no change in the rank when a smaller rank node is merging into a larger rank node
            parent[b] = a;
            if (Rank[a] == Rank[b])
            {
                Rank[a]++;
            }
        }
    }

    bool isSameComponent(int u, int v){
        return findSet(u) == findSet(v);
    }
};

int main()
{

    // no of edges : total number of connected components -1
    int n, m1, m2;
    cin >> n >> m1 >> m2;

    DSU dsu1(n);
    DSU dsu2(n);
    for (int i = 1; i <= m1; i++)
    {
        int u, v;
        cin >> u >> v;
        dsu1.unionSet(u, v);
    }

    for (int i = 1; i <= m2; i++)
    {
        int u, v;
        cin >> u >> v;
        dsu2.unionSet(u, v);
    }

    vector<pair<int,int>> edge;

    for(int i = 1; i <= n ;i ++){
        for(int j = i+1; j <= n; j ++){
            //cout << i << " " << j << endl;
            if( (!dsu1.isSameComponent(i,j)) && (!dsu2.isSameComponent(i,j)) ){
                dsu1.unionSet(i,j);
                dsu2.unionSet(i,j);
                edge.push_back({i,j});
            }
        }
    }

    cout << edge.size() << endl;

    for(int i = 0 ; i < edge.size() ; i ++){
        int u = edge[i].first;
        int v = edge[i].second;

        cout << u << " " << v << endl;
    }
    return 0;
}