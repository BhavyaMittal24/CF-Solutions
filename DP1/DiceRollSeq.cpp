#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    cin >> n;

    // dp[i][prev] : min no of moves reqd to make sequence from i to n-1 a valid one sich that the prev rollout number is "prev"
    // prev = 0 means no number

    vector<int> arr(n);

    // dp[i][curr]

    // 0, 1 ,,,,    i,             n-1
    //              currFace

    //
    for(int i = 0; i < n; i ++){
        cin >> arr[i];
    }
    vector<vector<int>> dp(n+1, vector<int> (7,1e9));
    // min no of moves reqd

    for(int prev = 0; prev <= 6; prev ++){
        dp[n][prev] = 0;
    }

    // dp[i][curr] = min( j : 1,6 op + dp[i+1][j])

    for(int i = n-1 ; i >= 0; i --){

        for(int curr = 1; curr <= 6; curr ++){

            for(int nextFace = 1; nextFace <= 6; nextFace ++){
                if( curr == nextFace || (nextFace + curr == 7)) continue;

                int op = (curr == arr[i]) ? 0 : 1;
                dp[i][curr] = min(dp[i][curr], op + dp[i+1][nextFace]);
            }
        }
    }

    int minOps = 1e9;

    for(int i = 1; i <= 6; i ++)
    {
        minOps = min(minOps, dp[0][i]);
    }

    cout << minOps << "\n";
    return;
}
int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while(t--){
        solve();
    }

}