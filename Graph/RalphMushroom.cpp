#include <bits/stdc++.h>
using namespace std;

long long findNoOfIterations(long long weight)
{

    // i*i+1 /2 <= weight

    long long low = 1;
    long long high = weight;

    long long ans = 0;

    while (low <= high)
    {
        long long mid = (low + high) / 2;

        if (1ll * mid * (mid + 1) / 2 <= weight)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

long long totalMushroomsCollected(long long weight)
{

    long long k = findNoOfIterations(weight);

    long long total = 1ll * (k + 1) * weight;

    total -= 1ll * k * (k + 1) * (k + 2) / 6;
    return total;
}

vector<long long> topo;

void dfs(long long node, vector<long long> &vis, vector<vector<pair<long long, long long>>> &adj, bool getSCC, vector<long long> &component, vector<long long> &roots, long long color)
{

    vis[node] = 1;

    if (getSCC)
    {
        component.push_back(node);
        // color all the nodes belonging to one root
        roots[node] = color;
    }

    for (auto x : adj[node])
    {
        long long v = x.first;
        long long w = x.second;
        if (!vis[v])
            dfs(v, vis, adj, getSCC, component, roots, color);
    }

    if (!getSCC)
    {
        topo.push_back(node);
    }
}

void findMaxMushrooms(long long node, vector<long long> &vis, vector<vector<pair<long long, long long>>> &cond_adj, vector<long long> &mushCollectedInSCC, vector<long long> &dp)
{

    vis[node] = 1;

    dp[node] = mushCollectedInSCC[node];

    long long valNode = mushCollectedInSCC[node];
    for (auto x : cond_adj[node])
    {
        long long v = x.first;
        long long wt = x.second;
        if (vis[v] == 0)
            findMaxMushrooms(v, vis, cond_adj, mushCollectedInSCC, dp);
        long long possibleVal = 1ll * wt + valNode + dp[v];
        dp[node] = max(dp[node], possibleVal);
    }

    return;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, m;

    cin >> n >> m;

    // there can be edges to a node itself
    // u -> v can share the same edge mutiple times

    vector<vector<pair<long long, long long>>> adj(n + 1);
    vector<vector<pair<long long, long long>>> rev_adj(n + 1);

    for (long long i = 0; i < m; i++)
    {
        long long u, v, w;
        cin >> u >> v >> w;
        // u -> v, w : path from u to v with weight w
        adj[u].push_back({v, w});
        rev_adj[v].push_back({u, w});
    }

    long long s;
    cin >> s;
    // find the scc
    vector<long long> vis(n + 1, 0);

    vector<long long> component;

    vector<long long> roots(n + 1, 0);

    for (long long i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            dfs(i, vis, adj, false, component, roots, 0);
        }
    }

    // reverse th topo sort to get the output based on the tout time in the descending order : a sort of topologocal ordering u -> v
    reverse(topo.begin(), topo.end());

    // Perform the sae dfs on the reversed adjacency list in the order of the topologocla ordering : each node will be trapped : src -> sink
    // with the scc : you can go from any one node to another node from anywhere

    fill(vis.begin(), vis.end(), 0);

    vector<vector<long long>> components;

    // for each scc collect all the possible mushrooms along the edge weight
    vector<long long> mushCollectedInSCC(n + 1, 0);

    long long cnt = 1;
    for (long long node : topo)
    {

        vector<long long> component;

        // another method could have been to go to each of the nodes in the component and assing them the root value for : roots[node] = cnt;
        if (vis[node] == 0)
        {
            dfs(node, vis, rev_adj, true, component, roots, cnt);
            // for each scc: increment the cnt : index for the root
            cnt++;
            components.push_back(component);
        }
    }

    for (auto component : components)
    {
        // Post condensation for the scc, store it's values fpr mushrooms collected
        for (long long sccNode : component)
        {

            for (auto x : adj[sccNode])
            {

                long long v = x.first;
                long long wt = x.second;
                // sccNode -> v : but they should belong to the same SCC
                // in one scc, cover all possible paths from one node to another : all edges from one node to it's neighbours for each node
                if (roots[v] == roots[sccNode])
                {
                    long long val = totalMushroomsCollected(wt);
                    mushCollectedInSCC[roots[v]] += val;
                }
            }
        }
    }

    long long totalRootNodes = cnt - 1;

    // option 2 :
    // go to components for each scc and then form the value and store in mushCOllectedInSCC[roots[u]] +=

    // apply dp

    // form a condensed adj list

    vector<vector<pair<long long, long long>>> cond_adj(n + 1);

    // or alternatively : go to components : component and for each component try to see it's neighbours and connect the respective roots together when they don't belong to the same SCC
    for (long long i = 1; i <= n; i++)
    {
        for (auto x : adj[i])
        {
            long long v = x.first;
            long long wt = x.second;
            // i -> v,w
            if (roots[i] != roots[v])
            {
                cond_adj[roots[i]].push_back({roots[v], wt});
            }
        }
    }

    vector<long long> dp(n + 1, 0);

    fill(vis.begin(), vis.end(), 0);

    findMaxMushrooms(roots[s], vis, cond_adj, mushCollectedInSCC, dp);

    cout << dp[roots[s]] << endl;
    return 0;
}