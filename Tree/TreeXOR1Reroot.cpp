#include <bits/stdc++.h>
using namespace std;

int N = 2e5+1;

void dfs(int node, int parent, vector<vector<int>> &adj, vector<long long> &cost, vector<int> &sz, vector<int> &val)
{
    sz[node] = 1;

    for (int x : adj[node])
    {
        if (x != parent)
        {
            dfs(x, node, adj, cost, sz, val);
            sz[node] += sz[x];
            cost[node] += (cost[x] + 1ll*sz[x] * (val[node] ^ val[x]));
        }
    }
}

void changeRoot(int oldRoot, int newRoot, vector<int> & sz, vector<int> & val, vector<long long> & cost){
   
    // break the bond
    cost[oldRoot] -= ( cost[newRoot] + sz[newRoot] * 1ll*(val[oldRoot] ^ val[newRoot]) );

    sz[oldRoot] -= sz[newRoot];


    // add a new bond
    cost[newRoot] += ( cost[oldRoot] + sz[oldRoot] * 1ll*(val[oldRoot] ^ val[newRoot] ) );

    sz[newRoot] += sz[oldRoot];

    //cost[newRoot] += minCost[newRoot];
}

void reroot(int node, int parent, vector<vector<int>> &adj, vector<int> &sz, vector<int> &val, vector<long long> &minCost, vector<long long> &cost)
{

    minCost[node] = cost[node];

    int n = adj.size() - 1;

    for (int x : adj[node])
    {
        if (x != parent)
        {
            changeRoot(node, x, sz, val, cost);
            reroot(x, node, adj, sz, val, minCost, cost);
            changeRoot(x, node, sz, val, cost);
        }
    }
}

void solve() 
{

    int n;
    cin >> n;
    vector<int> val(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> val[i];
    }

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<long long> cost(n + 1, 0);

    vector<int> sz(n + 1, 0);

    dfs(1, 0, adj, cost, sz, val);

    vector<long long> minCost(n + 1, 0);

    minCost[1] = cost[1];
    reroot(1, 0, adj, sz, val, minCost, cost);

    for (int i = 1; i <= n; i ++)
    {
        cout << minCost[i] << " ";
    }
    cout << endl;

    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}