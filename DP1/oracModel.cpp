// 4
// 4
// 5 3 4 6
// 7
// 1 4 2 3 6 4 9
// 5
// 5 4 3 2 1
// 1
// 9

// rac wants to know the maximum number of models that he can buy, and he may ask you these queries many times.

// print max no of elements in the subsequence :

// a1 ………..ai aj …….an

// a1 ai  aj..  an
//    i  j

// any adjacent element in the subsequence should have :

// j > i
// aj > ai (cant be equal)

// j is divisible by i

// size : 1 4 2 3 6 4 9
// index: 1 2 3 4 5 6 7

// index 1, 3, 6   j % i = 0
//       1  2  4 : si < sj

// 1 based index : size  : 1 4 2 3| 6 4 9

//                 index : 1 2 3 4

//      [         i]
//              s[i]

// [i      ]
// s[i]

// starting index is i,

// 1 2 4 8 ]

// 1 4 8
// 1 2 8
// 1 8
// cnt of maximum elements in array from  index i to n
// n  = 1e5

// dp[i] = 1 + max( dp[i*2] , dp[i*3],  dp[i*k]]  where s[i*k] > s[i];  i*k <=n

// final subproblem : dp[0]

// base case :

// // count of elements from index n to n with
// dp[n] = 1

// final subproblem : dp[0];

// // n = 7

// // 1 4 2 3 6 4 9

#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

// dp[i] : max elements in the subsequence from index i to n such that for any adjacent elements ai and aj in the subsequence, aj > ai and j is divisible by i 
void solve()
{

    int n;
    cin >> n;
    vector<long long> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];

    vector<long long> dp(n + 1, 1);

    dp[n] = 1;

    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 2 * i; j <= n; j += i)
        {
            if (arr[j] > arr[i])
            {
                dp[i] = max(dp[i], 1+dp[j]) % mod;
            }
        }
    }

     // Final result is the maximum value across the entire DP array
    long long max_len = 0;
    for (int i = 1; i <= n; i++) {
        max_len = max(max_len, dp[i]);
    }

    cout << max_len << endl;
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
