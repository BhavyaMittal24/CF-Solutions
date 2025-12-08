#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;

    // {x,y}  1<= x,y <= 2e5
    // to know which cordinate maps to which point
    map<pair<int, int>, int> mp;
    // {x,y} -> index

    pair<int, int> maxPair = {1e9, 1e9};
    vector<pair<int, int>> points(n);

    map<string, int> vis;
    // answer storing thr nearest excluded pponts
    //  initially all the nearest points are very far
    vector<pair<int, int>> answer(n, maxPair);

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    // q storing the coordinates for the points which ae excluded adjacent to other points
    // they can be connected to other nodes
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        mp[{x, y}] = i;
        points[i] = {x, y};
    }

    for (int i = 0; i < n; i++)
    {

        int x = points[i].first;
        int y = points[i].second;

        for (int j = 0; j < 4; j++)
        {
            int newRow = x + dx[j];
            int newCol = y + dy[j];

            // point  = i
            // not a part of the points set
            string key = newRow + "#" + newCol;
            if ( !vis[key]  &&  mp.find({newRow, newCol}) == mp.end())
            {
                q.push({newRow, newCol});
                vis[key] = 1;
            }
        }
    }

    while (!q.empty())
    {
        int qSize = q.size();
        while (qSize--)
        {
            auto p = q.front();
            int row = p.first;
            int col = p.second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int newRow = row + dx[i];
                int newCol = col + dy[i];

                // the adj of the excluded points must be a part of the points
                string key = newRow + "#" + newCol;
                if ( vis[key] == 0 && mp.find({newRow, newCol}) != mp.end())
                {
                    answer[mp[{newRow,newCol}]] = ( mp.find({row,col}) == mp.end()) ? make_pair(newRow, newCol) : answer[mp[{row, col}]];
                    q.push({newRow, newCol});
                    vis[key] = 1;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << answer[i].first << " " << answer[i].second << endl;
    }

    return 0;
}