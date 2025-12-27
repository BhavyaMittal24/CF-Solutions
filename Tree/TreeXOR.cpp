#include <bits/stdc++.h>
using namespace std;

long long minValue = 1e18;

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

void changeRoot(int oldRoot, int newRoot, vector<int> & sz, long long newCost){
    
    sz[oldRoot] -= sz[newRoot];

}

void reroot(int node, int parent, vector<vector<int>> &adj, vector<int> &sz, vector<int> &val, vector<long long> &minCost, long long prevCost)
{

    minValue = min(minValue, prevCost);
    minCost[node] = prevCost;

    int n = adj.size() - 1;

    for (int x : adj[node])
    {
        if (x != parent)
        {
            long long newCost = prevCost + 1ll*(n - 2 * sz[x]) * 1ll*(val[x] ^ val[node]);
            reroot(x, node, adj, sz, val, minCost, newCost);
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

    long long rootCost = cost[1];

    vector<long long> minCost(n + 1, 0);
    reroot(1, 0, adj, sz, val, minCost, rootCost);

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