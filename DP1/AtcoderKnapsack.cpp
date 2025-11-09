#include<bits/stdc++.h>
using namespace std;


// n < 100
// w <= 1e9
//vi <= 1e3

int main(){

    int n, W;
    cin >> n >> W;

    vector<int> weight(n);
    vector<int> value(n);

    for(int i=0;i<n;i++){
        cin >> weight[i] >> value[i];
    }

    // max possible cost is 1e5
    // dp[i][cost] : is the minimum weight possible to get exactly a cost from set of i elemetns in suffix i to n-1

    // Weight can be 1 to 1e9

    // dp[i][cost] = min( wi + dp[i+1][cost - vi] if cost >=vi , dp[i+1][cost] )
    // dp[n][cost] = 1e18 : infinite weight : not [ossible]

    // dp[anthin][0] = 0
    // max cost I can form
    int N = 100000;

    vector<vector<long long>> dp(n+1, vector<long long>(N+1, 0));
    for(int cost = 1; cost <=N;cost++){
        dp[n][cost] = 1e18;
    }
    // impossible to make the cost non zero from a set of 0 elements so min weight is inficniite

    // qnother base case : dp[i][> 1e5] : max cost greater than all : already npt possiblr
    dp[n][0] = 0;

    int maxCost = 0;
    for(int i=n-1;i>=0;i--){
        for(int cost = 1;cost<=N;cost++){

            long long notTake = dp[i+1][cost];
            long long take = 1e18;
            if(cost >= value[i]) {
                if( dp[i+1][cost - value[i]] != 1e18 ) take = weight[i] + dp[i+1][cost - value[i]];
            }

            dp[i][cost] = min(take, notTake);

            if(dp[i][cost] <= W ){
                maxCost = max(maxCost, cost);
            }
        }
    }
    cout << maxCost << endl;
    return 0;
}