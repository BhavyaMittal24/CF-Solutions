   

#include<bits/stdc++.h>
class Solution {
public:

    
    int inf = 1e9;
    int dp[105][105][25];


    int minCost(vector<int>& houses, vector<vector<int>>& cost, int n, int k, int target) {

        // iterative dp
        // dp[i][target][prevHouseColor] represents the min cost to paint all the houses from i to n-1 such that there are exactly 'targets' group of consecutive segments with sqme color where currColor is the current of the ith house

        // base case
        //target = 0 : ans = 0;

        // dp[n][>=1][anything] = inf

        // transitiom

        // if target < 0 at anytime : just make it inf;
        // dp[i][target][prevHouseColor] = 

    // case1
    //     house[i] != 0

    // A. colorHouse == prevColor -> dp[i+1][target][colorHouse]
    // b. colorHouse != prevHouseColor -> dp[i+1][target -1][colorHouse]

    // case 2
    //     house[i] == 0
    
    // A. Assign a new color to the house
    //     colorHouse != prevHouse -> cost[i][colorHouse] + dp[i+1][target-1][colorHouse]
    //     colorHouse == prevHouse -> cost[i][prevHouse] + dp[i+1][target][colorHouse]

    // }

    memset(dp,inf, sizeof(dp));

    // dp[n][0][anything] = 0;
    // dp[n][>0][anytging] - inf;

    for(int color = 1; color<= k ;color++) dp[n][0][color] = 0;

    // i,target -> i+1, target-1, color

    for(int i = n-1; i >= 0; i--)
    {

        for(int target = 0; target <= n; target++)
        {
            for(int prevColor = 1; prevColor <= k; prevColor++)
            {

                // room for painitng the house
                if(houses[i] == 0){

                    // assing any color to the house i
                    for(int chosenColor = 1; chosenColor <= k; chosenColor ++){
                        if( prevColor == chosenColor){
                            dp[i][target][prevColor] = min( dp[i][target][chosenColor], dp[i+1][target][chosenColor] + cost[i][chosenColor-1]); 
                        }
                        // prevColor != chosenColor
                        else {
                            // when no room for a different color and you wnt tp put a diff color from the prevCOlor -> Invalid case
                            if(target == 0) dp[i][target][prevColor] = min(dp[i][target][prevColor], inf);

                            else dp[i][target][prevColor] = min(dp[i][target][prevColor] , cost[i][chosenColor-1] + dp[i+1][target-1][chosenColor] );
                        }
                    }
                }
                else {

                    if(houses[i] == prevColor){
                        dp[i][target][prevColor] =  min( dp[i][target][prevColor], dp[i+1][target][houses[i]]);
                    }
                    else {
                        if(target == 0) dp[i][target][prevColor] = inf;
                        else dp[i][target][prevColor] =  min( dp[i][target][prevColor], dp[i+1][target-1][houses[i]]);
                    }
                }
            }
        }

    }
        // dp[0][target][prevColor]:
        // prevColor can be any from 1 to k and we can try:
        // find the mincost

        int ans = inf;
        for(int prev = 1; prev<=k; prev++){
            ans = min(ans, dp[0][target][prev]);
        }

        return (ans == inf) ? -1 : ans;
    }
    
};
