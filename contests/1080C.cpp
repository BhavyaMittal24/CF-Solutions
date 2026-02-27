#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    cin >> n;
    
    vector<int> arr(n,0);

    for(int i = 0; i < n; i ++) cin >> arr[i];

    vector<vector<int>> dp(n+1, vector<int> (7, 1e9));
    // infiinte min op to make it valid

    for(int i = 1; i <= 6; i ++){
        dp[n][i] = 0;
    }

    // final answer : dp[0][0]

  
    for(int i = n-1; i>= 0; i --){

        for(int prev = 0; prev <= 6; prev++){

            int minAns = INT_MAX;
            for(int num = 1; num <= 6; num++){

                if( num == prev || num == (7 -prev)){
                    continue;
                }

                if(num != arr[i]) {
                    minAns = min(1 + dp[i+1][num], minAns);
                }
                else {
                    minAns = min(dp[i+1][num], minAns);
                }
            }
            dp[i][prev] = minAns;
        }
    }

    cout << dp[0][0] << "\n";
    return;
}
int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}