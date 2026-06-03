#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, x, s;
    cin >> n >> x >> s;

    string friends;
    cin >> friends;

    // Use a solid unreached marker value
    const int INF = 1e9;
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, -INF));
    
    // The only true base case before any friend is processed
    dp[0][0] = 0;

    for(int i = 1; i <= n; i ++){
        char p = friends[i - 1]; // FIX: 0-indexed string mapping

        for(int u = 0; u <= x; u ++){
            // 1. Skip / Kick Out Option is always available if previous state was valid
            if (dp[i-1][u] != -INF) {
                dp[i][u] = max(dp[i][u], dp[i-1][u]);
            }

            // 2. Evaluate Seating Options
            // We read from the clean previous row state (dp[i-1]) to compute updates
            
            // Introvert / Ambivert Option (Open a new table)
            if (p == 'I' || p == 'A') {
                if (u > 0 && dp[i-1][u-1] != -INF) {
                    dp[i][u] = max(dp[i][u], dp[i-1][u-1] + 1);
                }
            }

            // Extrovert / Ambivert Option (Sit at an existing table)
            if (p == 'E' || p == 'A') {
                if (u > 0 && dp[i-1][u] != -INF) {
                    int totalPlaced = dp[i-1][u];
                    if (totalPlaced < (u * s)) {
                        dp[i][u] = max(dp[i][u], totalPlaced + 1);
                    }
                }
            }
        }
    }

    // Find the maximum value in the final row across all valid table outcomes
    int ans = 0;
    for(int u = 0; u <= x; u++){
        ans = max(ans, dp[n][u]);
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}