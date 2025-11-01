#include <bits/stdc++.h>
using namespace std;

// Global C-style array for maximum memory efficiency.
// This resolves the memory overhead associated with nested std::vectors.
// The state is: dp[i][l][sl], where i up to N, l and sl are 0 or 1.
int dp[200005][2][2];
const int INF = 500000; // Large constant for impossible paths

// Recursive DP function (Memoized Top-Down)
// dp[i][l][sl] = min operations required to make players i to n-1 optimal,
// given desired attacks of player i-1 is 'l' and player i-2 is 'sl'.
int moves(int i, int l, int sl, string s, int s0_desired, int s1_desired)
{
    int changes = INF;
    int n = s.length();

    // Base Case: We are at the last player (n-1).
    if (i == n - 1)
    {
        // We must check if the desired attack (0 or 1) at n-1 is valid based on the
        // fixed boundary conditions (l, sl, s0_desired, s1_desired).

        // Try placing L (0) at n-1
        // (l, sl) are s[n-2], s[n-3]. (s0_desired, s1_desired) are s[0], s[1].
        if ((l != 0 || sl != 0) && (s0_desired != 0 || s1_desired != 0) && (l != 0 || s0_desired != 0))
        {
            int cnt = (s[i] == 'L') ? 0 : 1; // 0 if match, 1 if flip needed
            changes = min(changes, cnt);
        }

        // Try placing R (1) at n-1
        if ((l != 1 || sl != 1) && (s0_desired != 1 || s1_desired != 1) && (l != 1 || s0_desired != 1))
        {
            int cnt = (s[i] == 'R') ? 0 : 1; // 0 if match, 1 if flip needed
            changes = min(changes, cnt);
        }

        return changes;
    }

    if (dp[i][l][sl] != -1)
        return dp[i][l][sl];

    // Option 1: Current player i attacks R (1)
    int placeRight = INF;
    // Transition condition: Check if attacking R (1) at i is valid based on l (i-1) and sl (i-2)
    if (l != 1 || sl != 1)
    {
        int current_flip = (s[i] == 'R') ? 0 : 1;
        placeRight = current_flip + moves(i + 1, 1, l, s, s0_desired, s1_desired);
    }

    // Option 2: Current player i attacks L (0)
    int placeLeft = INF;
    // Transition condition: Check if attacking L (0) at i is valid based on l (i-1) and sl (i-2)
    if (l != 0 || sl != 0)
    {
        int current_flip = (s[i] == 'L') ? 0 : 1;
        placeLeft = current_flip + moves(i + 1, 0, l, s, s0_desired, s1_desired);
    }

    return dp[i][l][sl] = min(placeLeft, placeRight);
}

void solve()
{

    int n;
    if (!(cin >> n))
        return;
    string s;
    cin >> s;

    if (n <= 2)
    {
        cout << 0 << endl;
        return;
    }

    int ans = n;

    // Iterate over the four possible fixed states for the first two players (s[0] and s[1])
    for (int s0_desired = 0; s0_desired <= 1; s0_desired++)
    { // Desired s[0] (0=L, 1=R)
        for (int s1_desired = 0; s1_desired <= 1; s1_desired++)
        { // Desired s[1] (0=L, 1=R)

            // 1. Calculate initial flips for s[0] and s[1]
            int current_flips = 0;
            current_flips += (s0_desired == 0) ? (s[0] != 'L') : (s[0] != 'R');
            current_flips += (s1_desired == 0) ? (s[1] != 'L') : (s[1] != 'R');

            // 2. Initialize DP table before each new case
            memset(dp, -1, sizeof(dp));

            // 3. Run recursive DP starting from index 2
            // l = s1_desired (s[1]), sl = s0_desired (s[0])
            int total_from_dp = moves(2, s1_desired, s0_desired, s, s0_desired, s1_desired);

            // 4. Update answer if the path was reachable
            if (total_from_dp < INF)
            {
                ans = min(ans, total_from_dp + current_flips);
            }
        }
    }
    cout << ans << endl;
}
int main()
{
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
