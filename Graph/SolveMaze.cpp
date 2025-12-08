#include <bits/stdc++.h>
using namespace std;
;

void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>> &maze)
{
    vis[row][col] = 1;

    int n = maze.size();
    int m = maze[0].size();

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    for (int i = 0; i < 4; i++)
    {
        int newRow = row + dx[i];
        int newCol = col + dy[i];

        if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && vis[newRow][newCol] == 0 && maze[newRow][newCol] != '#')
        {
            dfs(newRow, newCol, vis, maze);
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> good;
    vector<pair<int, int>> bad;

    vector<vector<char>> maze(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char letter;
            cin >> letter; 
            maze[i][j] = letter;

            if (maze[i][j] == 'G')
            {
                good.push_back({i, j});
            }

            else if (maze[i][j] == 'B')
            {
                bad.push_back({i, j});
            }
        }
    }

    //cout << good.size() << " " << bad.size() << endl;
    if (good.size() == 0 && bad.size() == 0)
    {
        cout << "Yes" << endl;
        return;
    }

    // no good but bad is present : block the last cell
    else if (good.size() == 0)
    {
        cout << "Yes" << endl;
        return;
    }

    // case when good is present, and bad may also be present

    // check if good cells are reachable or not : when all bad cells surroundings are blcoked by walls

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    for (int i = 0; i < bad.size(); i++)
    {
        int row = bad[i].first;
        int col = bad[i].second;

        for (int j = 0; j < 4; j++)
        {
            int adjRow = row + dx[j];
            int adjCol = col + dy[j];

            if (adjRow >= 0 && adjRow < n && adjCol >= 0 && adjCol < m && maze[adjRow][adjCol] == '.')
            {
                maze[adjRow][adjCol] = '#';
            }
        }
    }

    // check if i can visit all the good people, and they can reach n-1, m-1 : they will be connected adfterall

    vector<vector<int>> vis(n, vector<int>(m, 0));

    // only the first g person should be able  to reach the end cell and so should the others
    int startRow = good[0].first;
    int endRow = good[0].second;

    dfs(startRow, endRow, vis, maze);

    bool isPossible = true;

    if (vis[n - 1][m - 1] == 0)
    {
        cout << "No" << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            //cout << vis[i][j] << " " ;
            // any G that does not reach the end
            if (maze[i][j] == 'G' && vis[i][j] == 0)
            {
                isPossible = false;
            }

            // any B that is connected and does reach the cell
            if (maze[i][j] == 'B' && vis[i][j] == 1)
            {
                isPossible = false;
            }
        }
        cout << endl;
    }

    if (isPossible)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}

int main()
{

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        solve();
    }

    return 0;
}