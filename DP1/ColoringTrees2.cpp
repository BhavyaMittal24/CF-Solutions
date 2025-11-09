#include<bits/stdc++.h>
using namespace std;

// dp[idx][subsets][color_index] stores the minimum cost to paint trees 
// from idx to n-1, starting with 'subsets' segments formed so far, 
// and the previous tree having color 'color_index - 1'.
// Since colors are 1 to M and the initial state is -1, 
// we map -1 to index 0, and colors 1..M to indices 1..M.
long long dp[101][101][101];
const long long INF = 1e18;

// idx: current tree index (0 to n-1)
// subsets: number of beautiful subsegments formed so far (0 to k)
// k: target number of subsegments
// currColor: color of the previous tree (-1 for initial state, 1 to m for colors)
long long minPaint(int idx, int subsets, int k, int currColor, vector<vector<int>>& paintPrice, vector<int> &trees){
    
    int n = trees.size();
    int m = paintPrice[0].size() - 1; // M is max color index

    // Base Case 1: All trees processed
    if(idx == n){
        // Success: Only return 0 cost if we achieved the target number of subsets
        return (subsets == k) ? 0 : INF;
    }

    // Base Case 2: Pruning - Not enough trees left to form the remaining required subsets
    // (n - idx) is the number of remaining trees. (k - subsets) is the number of required remaining subsets.
    if( (n - idx) < (k - subsets) ){
        return INF;
    }
    
    // Memoization Look-up
    // Map currColor (-1, 1..M) to a DP index (0, 1..M)
    int dp_color_idx = currColor + 1; 
    
    if(dp[idx][subsets][dp_color_idx] != -1) {
        return dp[idx][subsets][dp_color_idx];
    }
    
    long long minPaintCost = INF;

    // Case 1: Tree is already colored (trees[idx] != 0)
    if(trees[idx] != 0){
        int existingColor = trees[idx];

        // 1a: Continue the current segment (same color as previous)
        if(existingColor == currColor){
            // Cost is 0, segment count doesn't change
            minPaintCost = minPaint(idx + 1, subsets, k, existingColor, paintPrice, trees); 
        }
        // 1b: Start a new segment (different color from previous, or first tree)
        else {
            // Cost is 0, segment count increases
            minPaintCost = minPaint(idx + 1, subsets + 1, k, existingColor, paintPrice, trees);
        }
    }

    // Case 2: Tree is uncolored (trees[idx] == 0)
    else {
        // Iterate through all possible colors (1 to M)
        for(int color = 1; color <= m; color++){
            long long currentCost = paintPrice[idx][color];
            long long nextCost;
            
            // 2a: Continue the current segment (if possible)
            if(color == currColor){
                // Segment count is the same
                nextCost = minPaint(idx + 1, subsets, k, color, paintPrice, trees);
            }
            // 2b: Start a new segment
            else {
                // Segment count increases
                nextCost = minPaint(idx + 1, subsets + 1, k, color, paintPrice, trees);
            }
            
            // Only update minPaintCost if the recursive call didn't return INF
            if(nextCost != INF){
                minPaintCost = min(minPaintCost, currentCost + nextCost);
            }
        }
    }

    // Memoization Storage
    return dp[idx][subsets][dp_color_idx] = minPaintCost;
}

int main(){

    // Fast I/O is good practice in competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,k;
    cin >> n >> m >> k;

    // Initialize DP table with -1 (since 0 is a valid cost)
    // -1 signifies an uncomputed state
    memset(dp, -1, sizeof(dp)); 
    
    vector<int> trees(n,0);
    for(int i=0;i<n;i++) cin >> trees[i];

    // paintPrice[i][j] = cost to paint the i-th tree with color j
    vector<vector<int>> paintPrice(n, vector<int> (m+1,0));
    for(int i=0;i<n;i++){
        for(int j=1;j<=m;j++){
            cin >> paintPrice[i][j];
        }
    }

    // Start DP from index 0, with 0 subsets formed, and a previous color of -1 (initial)
    long long minCost = minPaint(0, 0, k, -1, paintPrice, trees);

    if(minCost >= INF) {
        cout << -1 << endl;
    }
    else{
        cout << minCost << endl;
    }
    return 0;
}
