#include <bits/stdc++.h>
using namespace std;

int countSetBits(int n)
{
    int cnt = 0;
    while (n > 0)
    {
        if (n % 2 == 1)
            cnt++;
        n = n / 2;
    }
    return cnt;
}
// dp[bitmask] : i -> set bits and n-i bits need to be set more. No of ways to permute n-i bits given i are already set
// ith index, i bits set : no of permutations from ith index to n-1  (n-i) given rest are set

// dp[0] : final ans

// dp[1 << n - 1] = 1; when all bits are set : no of ways to permute from n to n-1 = 1;

// transition : dp[bitmask] = i = 0 to n-1 , if ith bit is not set, dp[bitmask & ith bit]
int main()
{

    int n;
    cin >> n;

    const int maskSize = 1 << n;

    vector<vector<long long>> dp(n + 1, vector<long long>(maskSize, 0));

    // dp[anything][2^n-1] = 1

    // j = 0 to n-1
    // dp[i][bitmask] = dp[i+1][bitmask where jth bit is set]

    // when all the bits are set
    dp[n][maskSize - 1] = 1;

    // dp[(1 << n)-1] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < maskSize; j++)
        {
            // jth bit is not set in the bitmast
            int setBits = countSetBits(j);
            // case when the bit mask must have same bits set as the index
            if (i != setBits)
            {
                dp[i][j] = 0;
                continue;
            }

            long long cnt = 0;

            for (int k = 0; k < n; k++)
            {
                // in the mask j, if the kth bit is not set
                if (( j & (1 << k)) == 0)
                {
                    int nextMask = j | (1 << k);
                    cnt = cnt + dp[i + 1][nextMask];
                }
            }
            dp[i][j] = cnt;
        }
    }

    cout << dp[0][0] << endl;

    return 0;
}