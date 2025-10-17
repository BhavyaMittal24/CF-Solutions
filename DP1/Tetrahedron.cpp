
// returns the number of ways to go from current state to D
// // ( current state, no of steps taken so far)

// // n = 1 : D  : 1 path to go from D to D

// final subproblem : dp['D'][0]

// D -> A ->  B
//            C
//            D

//    > B

//    > C

#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

const int maxN = 1e7+1;
// return the number of ways to go from current state to D

long long countWays(char state, int steps, int n, vector<vector<long long>> &dp)
{
    if (steps == n)
    {

        if (state == 'D')
            return 1;
        // when the steps are equal to maxsteps but state is not 'D'

        return 0;
    }

    if (dp[state - 'A'][steps] != -1)
        return dp[state - 'A'][steps];

    vector<char> states = {'A', 'B', 'C', 'D'};

    long long ways = 0;

    for (int i = 0; i < 4; i++)
    {

        char nextState = states[i];
        if (nextState == state)
            continue;
        long long possibleWay = countWays(nextState, steps + 1, n,dp);
        if (possibleWay > 0)
            ways = (ways + possibleWay) % mod;
    }

    return dp[state - 'A'][steps] = ways;
}

int main()
{

    int n;
    cin >> n;
    vector<vector<long long>> dp(4, vector<long long>(n + 1, -1));
    long long ans = countWays('D', 0, n,dp);
    cout << ans << endl;
    return 0;
}