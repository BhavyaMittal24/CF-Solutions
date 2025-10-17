

// a[i] is between [1,m]   1  <= ai <=m

// ai ai+1 ….. 0 0 0 0 0 ai aj ..

// array of this sort with n numbers

// cnt of arrays

// arr[i] is known,  arr[i] -1, arr[i], arr[i]+1 can be taken by arr[i+1]

// only three possible values can be taken at i+1 th index and i-1th index

// 2 0 2 3 0 0 0 5
//   i
//       i
//     p v

// eg 0 5
//    8 5 return INT_MIN : invalid state
// dp[i, prevValue] = count of all valid arrays from index i to n and i-1 has a value prevElement where each adjacent element has absolute difference of atmost 1 | a[i] - a[i+1]| <= 1 for all i<=n-1 and >=0

// // prev element in the array
// // p can be between 1 to m only, if p >= m+1 or p <= 0 then an issue

// if arr[i] is a 0
// dp[i][p] = dp[i+1][p+1] + dp[i+1][p] + dp[i+1][p-1];

// if i == 0 and arr[i] == 0 then i can have 1 to m possibilities dp[0][anything] = dp[i+1][1] + dp[i+1][2] + …. dp[i+1][m]

// 0 based indexing

// base cases :
// if( i == n) return 0;
// dp[n][anything] = 0;

// // prev element can be generally between 1 to m
// // final ans can be max dp[0][anything] : first starting element can be anything 1 to m and I can have any value for it in case it's 0
// // 2 ..  -> dp[1][2]
// // 0 ai  ->  max dp[1][anything between 1 to m]

// // 0 0 0 0

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    const long long mod = 1e9 + 7;
    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 1; j <= m; j++)
        {

            if (i == n - 1)
            {
                if (arr[i] == 0)
                {
                    int cnt = 1;
                    if (j + 1 <= m)
                        cnt++;
                    if (j - 1 >= 1)
                        cnt++;
                    dp[i][j] = cnt;
                }
                else
                {
                    if (abs(arr[i] - j) <= 1)
                        dp[i][j] = 1;
                }
                continue;
            }

            if (arr[i] != 0)
            {
                if (abs(arr[i] - j) <= 1)

                    dp[i][j] = dp[i + 1][arr[i]];
            }
            else
            {
                dp[i][j] = dp[i + 1][j];
                if (j + 1 <= m)
                    dp[i][j] = (dp[i][j] +  dp[i + 1][j + 1]) % mod ;
                if (j - 1 >= 1)
                    dp[i][j] = (dp[i][j] + dp[i + 1][j - 1]) % mod  ;
            }
        }
    }

    long long count = 0;

    if(n == 1) {
        if(arr[0] == 0) cout << m << endl;
        else cout << 1 << endl;
        return 0;
    }
    if (arr[0] != 0)
    {
        count = dp[1][arr[0]];
    }
    else
    {
        for (int i = 1; i <= m; i++)
        {
            count = (count + dp[1][i]) % mod;
        }
    }

    cout << count << endl;

    return 0;
}

// 2 0 2

// 2 1 ->2

// 2 3 -> 3

// 2 2 -> 3