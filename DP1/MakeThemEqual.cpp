#include <bits/stdc++.h>
using namespace std;

// solve subproblem of getting themin no of moves to go from curr to desored using the operation
// int dp1[1001];
// int minMovesToMakeEqual (int curr, int des){

//     // not possible
//     if( curr > des){
//         return 1e9;
//     }

//     if(curr == des) return 0;

//     if(dp1[curr] != -1) return dp1[curr];
//     int moves = 0;
//     int subMoves = 1e9;
//     for(int x=1; x <= curr;x++){
//         int newNumber = (curr/x);
//         newNumber += curr;
//         subMoves = min(subMoves, minMovesToMakeEqual(newNumber, des));
//     }
//     if(subMoves != 1e9) moves = 1 + subMoves;
//     else moves = subMoves;

//     return dp1[curr] = moves;
// }

void solve()
{

    int n;
    int k;
    cin >> n >> k;

    vector<int> b(n);
    vector<int> c(n);

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    // int ways = minMovesToMakeEqual(1,1000);
    vector<int> dp1(1001, 1e9);

    dp1[1] = 0;
    for (int i = 1; i <= 1000; i++)
    {
        for (int x = 1; x <= i; x++)
        {
            int j = i + i / x;
            if (j <= 1000)
            {
                dp1[j] = min(dp1[j], dp1[i] + 1);
            }
        }
    }

    // dp[i][k] : maximum cost to make some elements ewul in atmost k operations
    // max k can be 12 : for a safe bet ; 14

    // dp[i][k] =
    // if b[i] == 1 : then just add cost[i] and dp[i+1][k]

    // dp[i][k] = dp[i+1][k] 0r
    // check if possivble to make b[i] from 1 : if yes :
    //          c[i] +  dp[i+1][k-minNoMoves]

    int totalSize = min(12000, k);
    vector<vector<long long>> dp(n + 1, vector<long long>(totalSize + 1, 0));

    // base case : dp[n][anything] = 0;

    // dp[i][0] = sum of ci where bi = 1; from i to n-1

    for (int i = n - 1; i >= 0; i--)
    {

        for (int steps = 0; steps <= totalSize; steps++)
        {
            long long cost = c[i];
            long long notMakeEqual = dp[i + 1][steps];
            long long makeEqual = 0;

            long long minMovesToMakeEqualToDes = dp1[b[i]];

            if (minMovesToMakeEqualToDes == 1e9 || minMovesToMakeEqualToDes > steps)
                makeEqual = 0;
            else
                makeEqual = cost + dp[i + 1][steps - minMovesToMakeEqualToDes];

            dp[i][steps] = max(makeEqual, notMakeEqual);
        }
    }

    // if(k <= 15000) cout << dp[0][k] << endl;
    // else cout << dp[0][15000] << endl;

    cout << dp[0][totalSize] << endl;
    //return 0;
}

int main(){

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}