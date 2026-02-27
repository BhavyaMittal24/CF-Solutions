#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    // cost to colour the ith house with jth color
    // color[i][j] : j belings to 0,1,2
    vector<vector<int>> cost(n, vector<int> (3,0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= 2; j ++){
            cin >> cost[i][j];
        }
    }

    // find the min cost required to color all the houses with colors 0,1,2 such that no adjacent houses have th3 same color

    // dp[i][prevColor ] : min cost required t ocolor all houses from i to n-1 such that i houses have already bee ncoloured

    vector<vector<int>> dp(n+1, vector<int> (3,1e9));

    // dp[n][anything ] = 0;
    dp[n][0] = 0;
    dp[n][1] = 0;
    dp[n][2] = 0;

    for(int i = n-1; i >= 0 ; i --){
        // int prevColor
        for(int j = 0; j <=2; j ++){

            // dp[i][j]
            int selectionCost = INT_MAX;
            for(int colorChosen = 0; colorChosen <= 2; colorChosen++){
                if(colorChosen == j) continue;

                selectionCost = min( selectionCost, dp[i+1][colorChosen] + cost[i][colorChosen]);
            }
            dp[i][j] = selectionCost;
        }
    }

    cout << min({dp[0][0], dp[0][1], dp[0][2]}) << endl;

    return 0;   
}