/*
This question is assessing if TC is familiar with dynamic programming or memoization using two-pointers.

NOTE: This is a warm-up question. The main question begins at the Follow-up Question 1.

In a city, there is a footpath constructed using blocks of different colors. There can be contiguous blocks of same color as well which makes the footpath beautiful.

A chief guest is going to visit the city and the city department wants to make the most beautiful footpath. Beauty value of the footpath is the largest number of continuous blocks painted with chief guest's favorite color.

You are given a positive number n (number of blocks in footpath) and number k (number of available colors for blocks). Each block can be painted with exactly one of the given colors (block_colors[i-1] is the color value of ith block, i starting from 1). Chief guest's favorite color is c (1 <= c <= k).

Warm-up question: Find the beauty value of the footpath.

Example 1: n=9 k=6 block_colors={6, 5, 2, 1, 2, 3, 2, 4, 5} c=2

There is footpath of 9 blocks having 6 different colors. Chief guest's favorite color is 2. Hence, beauty value is 1.

Example 2: n=10 k=6 block_colors={6, 5, 2, 1, 2, 2, 3, 4, 5, 2} c=2

In this case, the beauty value is 2.

int GetBeautyValue(const int n, const int k, const int c,
                   const std::vector<int>& block_colors) {
  // implement
}
Background
Let the candidate know they can assume the following

Question is very simple because it is meant to break the ice. TC should understand the question and provide a solution easily.
Constraints (TC should ask this, at least in the Follow-up Question 1):
1 <= n <= 1000
1 <= k <= 20
Common Issues
How to address frequently asked questions or places where the candidate commonly gets stuck

TC might have difficult time in understanding n, k, c which can be replaced with num_blocks, total_colors, favorite_color as well.
Make sure TC handles the edge case where the favorite color is not present.
Make sure TC handles the edge case where the largest continuous segment of blocks having the favorite color is at the end of the footpath.
Follow Up Question #1: Multiple queries with different favorite colors
Consider that there are q (1 <= q <= 10^5) queries with different favorite colors. The queries are stored in favorite_colors vector (which has length q).

Question: Return the beauty value for each of the q queries.

std::vector<int> GetBeautyValues(const int n, const int k,
                                 const std::vector<int>& favorite_colors,
                                 const std::vector<int>& block_colors) {
  // implement
}
Follow Up Question #2: Repaint blocks
Consider that the city department acts quick and tries to repaint at most m (1 <= m <= n) blocks such that the beauty value for a particular favorite color is maximized.

Question: Return the maximum beauty value possible after the repaint.

int GetMaximumBeautyValue(const int n, const int k,
                          const int c, const int m,
                          const std::vector<int>& block_colors) {
  // implement
}
Follow Up Question #3: Repaint blocks with different favorite colors
Consider that the city department acts quick and tries to repaint at most m (1 <= m <= n) blocks such that the beauty value is maximized. Also, there are q (1 <= q <= 10^5) queries with different favorite colors and maximum repaint count m. The queries are stored in favorite_colors vector and m vector (which have length q).

Question: Return the maximum beauty value possible after the repaint for each query.

std::vector<int> GetMaximumBeautyValues(const int n, const int k,
                                        const std::vector<int>& m,
                                        const std::vector<int>& favorite_colors,
                                        const std::vector<int>& block_colors) {
  // implement
}
Follow Up Question #4: Repaint blocks with different favorite colors in a circular footpath
Now consider that the footpath is circular, i.e., the start and end of the footpath are connected.

Question: Return the maximum beauty value possible after the repaint for each query.

std::vector<int> GetMaximumBeautyValuesCircular(const int n, const int k,
                                                const std::vector<int>& m,
                                                const std::vector<int>& favorite_colors,
                                                const std::vector<int>& block_colors) {
  // implement
}

*/


#include<bits/stdc++.h>
using namespace std;

// n, m , c : find the longest subarray with all the values as c

int findLongestSubWithValueC(int n, int c, vector<int> blockColors){

    int ans = 0; // when the value c is not present in the array

    for(int r = 0; r < blockColors.size(); r++){

        if( blockColors[r] == c) {

            int left = r;
            while( r < n && blockColors[r] == c){
                ans = max(ans, r - left + 1);
                r++;
            }
            // breaks at r = n or blockCOlors[r] != c, not a fv color
        }
        // if block[r] != c, and the nr++ 
    }
    return ans;
}

// n, q, ci : find the max subarray for each color in the array

vector<int> maxSubArrayFavColor(int q, int n, int k, vector<int> favColors, vector<int> blockColors){

    // compute the answer for each color : k <= 20
    // dp[k] : for each color you can compute the answrr for long est subbaray with all values c
    vector<int> maxSubArray(k+1, 0);

    for(int c = 1; c <= k; c ++){

        int ans = 0;
        for(int r = 0; r < n; r ++){
            if(blockColors[r] == c){
                int l = r;
                // l ........r till a[r] != c , r = r+1
                while( r < n && blockColors[r] == c){
                    ans = max(ans, r - l+1);
                    r++;
                }
            }
        }
        maxSubArray[c] = ans;
    }
    return maxSubArray;
}

// Slghtly hard : doable by you I feel :Sliding window + DP on slidnig window : i,j 
// where i is the max length subrra  with color c, for all subarays starting from i,
// [i.........] begins with i and has j repaints already done. Ans would be max value across all i,j

// find the max subarray length : Enough hint to try or think in direction if sliding window!!

int maxLengthSubArrayWithKColorMRepaints(int n, int m, int k, int c,  vector<int> blockColors){

    // m repaints are allowed : paint only blockColors[i] != c : and find the largest window where m paints have been done
    int l = 0;
    int r = 0;
    int ans = 0;

    // good subarray where no of repaints <= m, find the longest subbaray where the no of repaints = m
    // 0(N) time complexity for this
    // find the longest subbarray where the repaints <= m,
    //   l.... r 
    int repaints = 0;
    while( r < n){

        if(blockColors[r] == c){
            ans = max(ans, r - l+1);
        }
        else {
            repaints++;

            while(l <= r && repaints > m){
                if(blockColors[l] != c){
                    repaints--;
                }
                l++;
            }
        }
        // valid subbaraay
        if(repaints <= m){
            ans = max(ans, r-l+1);
        }

        r++;
    }
    return ans; // max length of subbaray when we can repaint m blocks in total and all values are c   
}


int maxSubArrayWithRepaint(int q, int n, int k, int m, vector<pair<int,int>> query, vector<int> colorBlocks){

    // K is the total colors, m is the max repaints allowed

    vector<vector<int>> maxSubLen(k+1, vector<int> (n+1, 0));
    for(int c = 1; c <= k; c ++){
        for(int m = 0; m <= n; m++){
            // c color, m repaints allowed, 
            // 0(n) time complecoty 
            int l = 0;
            int r = 0;
            int repaints = 0;
            int ans = 0;
            while( r < n){
                if(colorBlocks[r] == c){
                    ans = max(ans, r- l+1);
                }

                else {
                    if( repaints == m){
                        // we are considering to put color at r, so l < r
                        while( l < r && colorBlocks[l] == c){
                            l++;
                        }
                        if(l < r && colorBlocks[l] != c){
                            l++;
                            repaints--;
                        }
                    }

                    repaints++;
                    ans = max(r-l+1, ans);
                }
                r++;
            }
            maxSubLen[c][m] = ans;
        }
    }
}


int maxSubArrayWithRepaintCircle(int q, int n, int k, int m, vector<pair<int,int>> query, vector<int> colorBlocks){

    // K is the total colors, m is the max repaints allowed

    for(int i = 0; i < n-1; i ++){
        colorBlocks.push_back(colorBlocks[i]);
    }
    // 0 to n-1 0 1.. n-2 : n + n-1 : where max length is still n to n-1
    vector<vector<int>> maxSubLen(k+1, vector<int> (n+1, 0));
    for(int c = 1; c <= k; c ++){
        for(int m = 0; m <= n; m++){
            // c color, m repaints allowed, 
            // 0(n) time complecoty 
            int l = 0;
            int r = 0;
            int repaints = 0;
            int ans = 0;
            while( r < 2*n - 1){
                // length of subarray is more than possible
                if( r - l + 1 > n){
                    if(colorBlocks[l] != c) repaints ++;
                    l++;
                }

                if(colorBlocks[r] == c){
                    ans = max(ans, r- l+1);
                }

                else {
                    if( repaints == m){
                        // we are considering to put color at r, so l < r
                        while( l < r && colorBlocks[l] == c){
                            l++;
                        }
                        if(l < r && colorBlocks[l] != c){
                            l++;
                            repaints--;
                        }
                    }

                    repaints++;
                    ans = max(r-l+1, ans);
                }
                r++;
            }
            maxSubLen[c][m] = ans;
        }
    }
}