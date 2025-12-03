#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main()
{

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        //adj[v].push_back({u, w});
    }

    // u- > v,w

    // 1 to n : shortst distance

    // cost, node, usedOrNot

    // cost[node][1] : coupon used exactly once
    // cost[node][0] : cost ot reach from src to node where no coupon is used
    vector<vector<long long>> cost(n + 1, vector<long long>(2, INF));

    cost[1][0] = 0;

    // size of set is n : n*2 : n unique nodes

    // each pop : 0(n) log(setSize) + m*
    set<pair<long long, pair<int, int>>> st;

    // 0 , 1, 0
    st.insert({0, {1, 0}});

    while (!st.empty())
    {

        auto top = *st.begin();
        long long currCost = top.first;
        int node = top.second.first;
        int used = top.second.second;

        st.erase(st.begin());

        if (currCost > cost[node][used])
            continue;

        // when no coupon used up
        if (used == 0)
        {

            // Use the voucher now for any of the edges : or not use the voucher
            for (auto neighbour : adj[node])
            {
                int v = neighbour.first;
                int w = neighbour.second;

                // two options : add w or add w/2

                long long half = currCost + 1ll * w / 2;

                long long full = currCost + 1ll * w;

                if (cost[v][0] > full)
                {

                    // add half edge weight

                    cost[v][0] = full;
                    // voucher used up hre tp reach v

                    st.insert({cost[v][0], {v, 0}});
                }

                if (cost[v][1] > half)
                {

                    cost[v][1] = half;
                    st.insert({half, {v, 1}});
                }
            }
        }

        // voucher has been used up already
        else
        {

            for (auto neighbour : adj[node])
            {
                int v = neighbour.first;
                int w = neighbour.second;

                long long fullCost = currCost + 1ll * w;
                if (cost[v][1] > fullCost)
                {
                    cost[v][1] = fullCost;
                    st.insert({cost[v][1], {v, 1}});
                }
            }
        }
    }

    cout << cost[n][1] << endl;

    return 0;
}
