// minimizing the sum

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));

    vector<long long> suffix(n + 1, 0);

    suffix[n] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        suffix[i] = arr[i] + suffix[i + 1];
    }

    for (int i = 0; i <= k; i++)
        dp[n][i] = 0;

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = suffix[i];
    }

    // final ans : dp[0][k] : min sum from I to n-1 where no of op allowed is k

    for (int i = n - 1; i >= 0; i--)
    {

        for (int l = 1; l <= k; l++)
        {
            long long minVal = arr[i];
            long long noOp = arr[i] + dp[i + 1][l];
            long long op = 1e18;
            for (int j = i + 1; j <= i + l && j < n; j++)
            {
                minVal = min(minVal, arr[j]);
                long long lop = 1ll * minVal * (j - i + 1);
                lop = lop + dp[j + 1][l - (j - i)];
                op = min(lop, op);
            }
            dp[i][l] = min(op, noOp);
        }
    }

    cout << dp[0][k] << endl;
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