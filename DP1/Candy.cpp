// 3 4
// 1 2 3

// // N children a0 a1 a2 … an-1

// // k candies :
// // distribute k candies between n children such that each child gets between 0 and ai candy. all candies must be distributed

// 1 2 1
// 0 2 2
// 0 1 3
// 1 1 2
// 1 0 3

// 1≤N≤100
// 0≤K≤10^5
// 0≤ai≤K

//          j,[i
// dp[i][j]    a0 a1 …. ai .          an-1
// // no of ways to distribute j candies from I to n-1 children such that each child gets 0 to a[i] and no candy is left

// base case dp[n][j] = 0;

// dp[n-1][j] j> a[n-1] = 0

// dp[i][0] = 1;

// dp[i][j] = sum of dp[i+1][j] + dp[i+1][j-1] … dp[i+1][j-a[I]] .. max(0, j-a[i]);

// final ans  : dp[0][K]

#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int main()
{
    int n, K;
    cin >> n >> K;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<vector<long long>> dp(n + 1, vector<long long>(K + 1, 0));
    // 0 candies from I = i to n-1 : 1 way : don't give any candy to any kid

    vector<long long> prefix(K + 1, 1);
    vector<long long> prefix1(K + 1, 0);

    // dp[n][0] = 1;

    for (int i = 0; i <= n; i++) dp[i][0] = 1; 
    
    prefix[0] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        prefix1[0] = 1;
        for (int j = 1; j <= K; j++)
        {
            int left = max(0, j - a[i]);
            long long lower_sum = (left > 0) ? prefix[left - 1] : 0;
            dp[i][j] = ( prefix[j] - lower_sum + mod ) % mod;
            prefix1[j] = (prefix1[j - 1]  + dp[i][j]) % mod;
        }
        prefix = prefix1;
    }

    cout << dp[0][K] << endl;

    return 0;
}