// minimizing the sum

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    int m;
    cin >> n >> m;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<vector<long long>> dp(n + 1, vector<long long>(11, 1e10));
    // dp[i][k] = min sum of array from I to n-1 such that atmost k operations can be perform

    // dp[n][anything ] = 0;

    // dp[i] [k ]  - min (ai + dp[i+1][k]) , ai+1 + dp[i+1][k-1], ai-1 + dp[i+1][k-1];

    long long sum = 0;
    for (int i = 0; i < 10; i++)
    {
        dp[n][i] = 0;
    }

    for (int i = n - 1; i >= 0; i--)
    {

        for (int k = 0; k <= m; k++)
        {
            if (k == 0)
            {
                dp[i][k] = arr[i] + dp[i + 1][k];
                continue;
            }

            dp[i][k] = min(dp[i][k], arr[i] + dp[i + 1][k]);
            if (i - 1 >= 0)
                dp[i][k] = min(dp[i][k], arr[i - 1] + dp[i + 1][k - 1]);
            if (i + 1 < n)
                dp[i][k] = min(dp[i][k], arr[i + 1] + dp[i + 1][k - 1]);
        }
    }

    long long ans = 1e10;

    for(int i=0;i<=m;i++){
        ans = min(ans, dp[0][i]);
    }
    cout << ans << endl;
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