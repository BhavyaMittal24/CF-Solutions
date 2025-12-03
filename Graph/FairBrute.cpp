#include <bits/stdc++.h>
using namespace std;

// updates the min cost required to reach all the towns from towns of type i
void bfs(vector<int> towns, int type, vector<vector<int>> &cost, vector<vector<int>> &adj)
{

    queue<int> q;
    int n = cost.size() - 1;
    vector<int> vis(n + 1, 0);

    for (int i = 0; i < towns.size(); i++)
    {
        cost[towns[i]][type] = 0;
        q.push(towns[i]);
        vis[towns[i]] = 1;
    }

    // find the min cost to reach all towns from towns of good type

    int costing = 1;
    while (!q.empty())
    {

        int qSize = q.size();

        while (qSize--)
        {

            int node = q.front();
            q.pop();

            for (int x : adj[node])
            {
                if (vis[x] == 0)
                {
                    vis[x] = 1;
                    q.push(x);
                    cost[x][type] = costing;
                }
            }
        }
        costing++;
    }
}

int bfsCost(int town, vector<int> &type, vector<vector<int>> &adj, int s)
{

    // set of distinct goods present in all the towns reached so far
    set<int> goods;

    goods.insert(type[town]);

    queue<int> q;
    q.push(town);

    int n = adj.size() - 1;
    vector<int> vis(n + 1, 0);
    long long cost = 0;

    vis[town] = 1;

    long long distance = 1;

    while (!q.empty() && goods.size() < s)
    {

        int qSize = q.size();

        while (qSize-- && goods.size() < s)
        {

            int node = q.front();
            q.pop();

            for (int x : adj[node])
            {
                if (vis[x] == 0)
                {
                    vis[x] = 1;
                    q.push(x);

                    if (goods.find(type[x]) == goods.end())
                    {
                        cost += distance;
                        goods.insert(type[x]);
                        if (goods.size() == s)
                            break;
                    }
                }
            }
        }
        distance++;
    }
    return cost;
}
int main()
{

    int n, m, k, s;
    cin >> n >> m >> k >> s;

    // type of goods present in each node

    vector<int> type(n + 1);

    for (int i = 1; i <= n; i++)
    {
        // ith town, type of good associated to it
        cin >> type[i];
    }

    // adjacency list storing n nodes and theri adjacet nodes
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // cost[town][type ] : min cost required to reach from towni to a good j

    // fill in the table for cost[town][type]

    for (int i = 1; i <= n; i++)
    {

        int cost = bfsCost(i, type, adj, s);
        cout << cost << " ";
    }

    return 0;
}