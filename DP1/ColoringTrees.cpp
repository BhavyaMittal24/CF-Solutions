#include<bits/stdc++.h>
using namespace std;

//long long dp[101][101][102];
const long long INF = 1e18;

// idx : 0 - n-1
// currColor : 1 to m : base case  : -1 
// k : k to 0

long long minPaint(int idx, int subsets,int k, int currColor, vector<vector<int>>& paintPrice, vector<int> &trees){
    
    // function to calcluate the min cost ot pain trees with ci = 0 and have to be split into k subsegments with all elements in a segment having same color
    // from i to n-1
    int n = trees.size();

      // if not possible to form a very subset of size k, return 1e18 : nasiclly imposisible 

     
    if(idx == n && subsets == k){
        return 0;
    }

    if((n - idx)  < k - subsets){
        return INF;
    }
   
    //if(dp[idx][subsets][currColor+1] != -1) return dp[idx][subsets][currColor+1];
    int m = paintPrice[0].size() -1;
  

    long long minPaintCost = INF;
 
    long long sameColorCost = INF;
    long long diffColorCost = INF;

    // when tree is already coloured
    if(trees[idx] != 0){
        
        // if same color is there
        if( trees[idx] == currColor){
            sameColorCost = min(sameColorCost, minPaint(idx+1,subsets, k, currColor, paintPrice, trees) );
        }
        else {
            diffColorCost = min(diffColorCost, minPaint(idx+1,subsets+1, k, trees[idx], paintPrice, trees));
        }
    }

    //when we have to color the trees
    else {
        long long samePaint= INF;
        // you csnt take same paint if you have to make more k, but elements are n-i left
        if( currColor != -1) samePaint = minPaint(idx+1,subsets,k,currColor, paintPrice, trees);
        if(samePaint != INF) sameColorCost = paintPrice[idx][currColor] + samePaint;

        for(int i=1;i<=m;i++){
            if(i == currColor) continue;
            long long diffPaint = INF;
            diffPaint = minPaint(idx+1,subsets+1,k,i,paintPrice,trees);
            if(diffPaint != INF){
                diffColorCost = min(diffColorCost, paintPrice[idx][i] + diffPaint);
            }
        }
    }

    minPaintCost = min(sameColorCost, diffColorCost);
    //dp[idx][subsets][currColor+1] = minPaintCost;
    return minPaintCost;
}
int main(){

    int n,m,k;
    cin >> n >> m >> k;

    //memset(dp,-1,sizeof(dp));
    vector<int> trees(n,0);
    for(int i=0;i<n;i++) cin >> trees[i];

    vector<vector<int>> paintPrice(n, vector<int> (m+1,0));
    // paintPrice is 0 based indexing : 
    for(int i=0;i<n;i++){
        for(int j=1;j<=m;j++){
            // cost to paint the ith three, with jth color
            cin >> paintPrice[i][j];
        }
    }

    long long minCost = minPaint(0,0,k,-1,paintPrice, trees);

    if(minCost == INF) {
        cout << -1 << endl;
    }
    else{
        cout << minCost << endl;
    }
    return 0;
}