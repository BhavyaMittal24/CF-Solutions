#include <bits/stdc++.h>
using namespace std;

// distance of a given node to the node having a coin : farthestCoinDistance
// maxCoinDistance => {maxdistance from node having coin, node with max dist, node with second max distance}

// set score and maxCoinDistane in a subtree

int ans = INT_MAX;

void changeRoot(int currRoot, int newRoot, vector<pair<int, pair<int, int>>> &maxCoinDistance, vector<int> &score)
{

    auto curr = maxCoinDistance[currRoot];

    auto newObj = maxCoinDistance[newRoot];
    int farthestDistFromNewRoot = newObj.first;
    if (farthestDistFromNewRoot >= 2)
        score[currRoot] -= (2 + score[newRoot]);

    int currfirstMax = newObj.second.first;
    int currSecondMax = newObj.second.second;

    if (currfirstMax == newObj.first + 1)
    {
        currfirstMax = currSecondMax;
        currSecondMax = -1;
    }
    else if (currSecondMax == newObj.first + 1)
    {
        currSecondMax = -1;
    }

    // farthest height from a given node to the farthest coin node
    maxCoinDistance[currRoot] = {currfirstMax, {currfirstMax, currSecondMax}};

    int newFirstMax = newObj.first;
    int newSecondMax = newObj.second.second;

    if (currfirstMax + 1 >= 2)
    {
        score[newRoot] += score[currRoot] + 2;

        if (currfirstMax + 1 >= newFirstMax)
        {
            newSecondMax = newFirstMax;
            newFirstMax = currfirstMax + 1;
        }
        else if (currfirstMax + 1 >= newSecondMax)
        {
            newSecondMax = currfirstMax + 1;
        }
    }
    maxCoinDistance[newRoot] = {newFirstMax, {newFirstMax, newSecondMax}};
}

void reroot(int node, int parent, vector<vector<int>> &adj, vector<pair<int, pair<int, int>>> &maxCoinDistance, vector<int> &score)
{

    ans = min(ans, score[node]);
    for (int x : adj[node])
    {
        if (x != parent)
        {

            changeRoot(node, x, maxCoinDistance, score);
            reroot(x, node, adj, maxCoinDistance, score);
            changeRoot(x, node, maxCoinDistance, score);
        }
    }
}

void dfs(int node, int parent, vector<vector<int>> &adj, vector<pair<int, pair<int, int>>> &maxCoinDistance, vector<int> &score, vector<int> &coins)
{

    int firstMax = -1;
    int secondMax = -1;
    if (coins[node] == 1)
        firstMax = 0;

    for (int x : adj[node])
    {

        if (x != parent)
        {
            dfs(x, node, adj, maxCoinDistance, score, coins);

            auto distX = maxCoinDistance[x];
            int farthestCoinFromChild = distX.first;

            if (farthestCoinFromChild != -1)
            {
                if (firstMax < farthestCoinFromChild + 1)
                {
                    secondMax = firstMax;
                    firstMax = farthestCoinFromChild + 1;
                }
                if (farthestCoinFromChild >= 2)
                {
                    score[node] += (score[x] + 2);
                }
            }
        }
    }

    // by default for a leadf node if no coin then farthestLeafNode dist = -1
    // score is also 0
    pair<int, pair<int, int>> farthestAns = {firstMax, {firstMax, secondMax}};
    maxCoinDistance[node] = farthestAns;
}

int collectTheCoins(vector<int> &coins, vector<vector<int>> &edges)
{

    int n = coins.size();
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {

        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> score(n, 0);
    // distance of farthest coin from the node , firstMax, secondMax distance
    // -1 means that no coin under the subtree including the node : farthest : imposible
    vector<pair<int, pair<int, int>>> farthestCoinDistance(n, {-1, {-1, -1}});

    dfs(0, -1, adj, farthestCoinDistance, score, coins);

    reroot(0, -1, adj, farthestCoinDistance, score);
    return ans;
}