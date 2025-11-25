#include <bits/stdc++.h>
using namespace std;

int maxN = 3e5 + 5;
vector<int> edgeWeight(maxN, INT_MAX);

// given N nodes in a tree, and a root at 1, and two nodes u,v in each query, you need to find the minvalue in the path between a node x and y

// In time and outtime : helps us to find the ancestor/descendant for two given nodes.

// x   -> LCA -> y
// Brute force : Find the path from the root to node x and the path from root to node y. Store in vector and find the min value
// per query : Tc : 0(n)

// Use LCA (x,y)  : find the LCA in 0(logn)

// ensure to call these by  reference!
void dfs(int curr, int parent, vector<vector<pair<int, int>>> &par, vector<vector<pair<int, int>>> &adj, vector<int> &level)
{
    if (parent == 0)
    {
        level[curr] = 0;
    }
    else
        level[curr] = level[parent] + 1;

    // setting the value for the parent matrix  : derived from parents
    int m = par[0].size();
    par[curr][0] = {parent, edgeWeight[curr]};

    // curr -->>    2^i-1          --> 2^i-1 parent
    for (int i = 1; i < m; i++)
    {
        pair<int, int> ancestor2iMinus1 = par[curr][i - 1];
        par[curr][i] = {par[ancestor2iMinus1.first][i - 1].first, min(ancestor2iMinus1.second, par[ancestor2iMinus1.first][i - 1].second)};
    }

    for (auto x : adj[curr])
    {
        if (x.first != parent)
        {
            // weight from curr ->x : curr is the parent
            edgeWeight[x.first] = x.second;
            dfs(x.first, curr, par, adj, level);
        }
    }
}

pair<int, int> minDistance(int u, int v, vector<int> &level, vector<vector<pair<int, int>>> &par)
{

    if (u == v)
        return {u, 0};

    // depth of u is assumed to be greater than v
    if (level[u] < level[v])
    {
        swap(u, v);
    }

    int diff = level[u] - level[v];

    int Mn = INT_MAX;

    int m = par[0].size();
    // for findfing diffth paremt, we check what all bits are set in it, and then find the kth parent accordingly
    for (int i = 0; i < m; i++)
    {
        if (diff & (1 << i))
        {
            Mn = min(Mn, par[u][i].second);
            u = par[u][i].first;
        }
    }

    // u reaches the same depth as v

    if (u == v)
        return {u, Mn};
    for (int i = m - 1; i >= 0; i--)
    {
        if (par[u][i].first != par[v][i].first)
        {
            Mn = min(Mn, min(par[u][i].second, par[v][i].second));
            u = par[u][i].first;
            v = par[v][i].first;
        }
    }

    // both u and v are just below the LCA

    int LCA = par[u][0].first;
    Mn = min(Mn, min(edgeWeight[u], edgeWeight[v]));
    return {LCA, Mn};
}
int main()
{

    int n, M;
    cin >> n >> M;
    // nodes are numbered like indexes in a tree : Basically each node is unique indexed so that we can store them in the adjacency list

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // have a 2d Array storign the node, and its powers of 2 parents and their respective minvalues from that node to the 2^ith parent

    int m = log2(n) + 1; // no of bits

    vector<int> level(n + 1, 0);

    vector<vector<pair<int, int>>> par(n + 1, vector<pair<int, int>>(m, {0, INT_MAX}));

    // par[node][i] : { 2^ith parent, min value from node to the 2^ith parent}

    dfs(1, 0, par, adj, level);

    int q;
    cin >> q;
    vector<pair<int,int>> queries(q);
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        queries[i] = {x,y};
        // pair<int, int> LCA = minDistance(x, y, level, par);
        // cout << LCA.second << endl;
    }
       
    for (int i = 0; i < q; i++)
    {
        int x = queries[i].first;
        int y = queries[i].second;;
        pair<int, int> LCA = minDistance(x, y, level, par);
        cout << LCA.second << endl;
    }
    return 0;
}