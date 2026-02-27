#include<bits/stdc++.h>
using namespace std;

int main(){

    int n, k;
    cin >> n >> k; 

    // cost to colour the ith house with jth color
    // color[i][j] : j from 0 to k-1
    // k colors are presemt
    // do this in 0(n*k)

    vector<vector<int>> cost(n, vector<int> (k,0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= k-1; j ++){
            cin >> cost[i][j];
        }
    }

    // find the min cost required to color all the houses with colors 0,1,2 such that no adjacent houses have th3 same color

    // dp[i][prevColor ] : min cost required t ocolor all houses from i to n-1 such that i houses have already bee ncoloured

    vector<pair<pair<long long, int>, long long>> dp(n+1);

    // dp[n][anything ] = 0;

    dp[0] = { {0, k },0 };
    

    for(int i = 1; i <=n ; i ++){
        // int prevColor
        auto prevHouseInfo = dp[i-1];
        long long minVal = prevHouseInfo.first.first;
        int minColor = prevHouseInfo.first.second;
        long long secondMinVal = prevHouseInfo.second;

        long long currMinVal = 1e18;
        long long currMinColor = k;
        long long currSecondMinVal = 1e18;

        for(int j = 0; j < k; j ++){
            
            long long val = 0;
            if(j == minColor){
                val = secondMinVal + cost[i-1][j];
            }
            else {
                val = minVal + cost[i-1][j];
            }

            if( val < currMinVal){
                currSecondMinVal = currMinVal;
                currMinVal = val;
                currMinColor = j;
            }

            else if( val < currSecondMinVal){
                currSecondMinVal = val;
            }
        }
        dp[i] = {{currMinVal,currMinColor} , currSecondMinVal};
    }


    cout << dp[n].first.first;

    return 0;   
}