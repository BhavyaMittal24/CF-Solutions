#include <bits/stdc++.h>
using namespace std;

// dp[i][st1 for activits chosen] [st2 for days chosen] = maxfrineds for number of days from i to

const int N = 1e5 + 1;

long long dp[N][2][2][2];

void solve()
{

    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    for(int i = 0; i < 2; i ++){
        for(int j = 0; j < 2; j ++){
            for(int k = 0; k < 2; k ++){
                dp[n][i][j][k] = 0;
            }
        }
    }
    // dp[day][i][j][k]

    for (int day = n - 1; day >= 0; day--)
    {

        for (int i = 0; i <= 1; i++)
        {
            for (int j = 0; j <= 1; j++)
            {
                for (int k = 0; k <= 1; k++)
                {

                    long long max1 = 0;
                    if (i == 0)
                    {
                        max1 = a[day] + dp[day + 1][1][j][k];
                    }

                    long long max2 = 0;
                    if (j == 0)
                    {
                        max2 = b[day] + dp[day + 1][i][1][k];
                    }

                    long long max3 = 0;
                    if (k == 0)
                    {
                        max3 = c[day] + dp[day + 1][i][j][1];
                    }

                    dp[day][i][j][k] = max({dp[day + 1][i][j][k], max1, max2, max3});
                }
            }
        }
    }

    cout << dp[0][0][0][0] << "\n";

    return;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}