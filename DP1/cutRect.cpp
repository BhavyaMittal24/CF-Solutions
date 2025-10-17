
#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> dp;

long long countWays(int a, int b)
{
    if (a <= 0 || b <= 0)
        return 0;

    if (a == b)
        return 0;

    if (dp[a][b] != -1)
        return dp[a][b];
    long long cutA = LONG_LONG_MAX;
    long long cutB = LONG_LONG_MAX;

    if (a > 1)
    {

        for (int i = 1; i <= a / 2; i++)
        {
            cutA = min(cutA, countWays(i, b) + countWays(a - i, b));
        }
    }
    if (b > 1)
    {
        for (int i = 1; i <= b / 2; i++)
        {
            cutB = min(cutB, countWays(a, i) + countWays(a, b - i));
        }
    }
    return dp[a][b] = 1 + min(cutA, cutB);
}

int main()
{

    int a, b;
    cin >> a >> b;
    dp.resize(a + 1, vector<long long>(b + 1, -1));
    cout << countWays(a, b) << endl;
    return 0;
}