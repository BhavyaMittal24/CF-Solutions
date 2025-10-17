

#include <bits/stdc++.h>
using namespace std;

int f(int u, int v)
{

    int resp;
    cout << u << " " << v << endl;
    cin >> resp;
    return resp;
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int ans = f(i, j);
            if (ans == 1)
                break;
        }
    }
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