#include<bits/stdc++.h>
using namespace std;

bool canCrossInLessThanEqualToMidJumps1(int mid, vector<vector<int>> &colorIndices, int n) {
    int k = colorIndices.size() - 1;

    for (int i = 1; i <= k; i++) {
        // We only care about colors that actually exist in the array
        if (colorIndices[i].empty()) continue; 

        int largeGapsCount = 0;
        bool colorFails = false;

        // Check gap from start (0) to first plank
        int prev = 0;
        
        // We add a virtual plank at n+1 to handle the final gap easily
        vector<int> currentPlanks = colorIndices[i];
        currentPlanks.push_back(n + 1);

        for (int pos : currentPlanks) {
            int gap = pos - prev - 1;
            
            if (gap > mid) {
                largeGapsCount++;
                // If the gap is so big even halving it doesn't help...
                // OR if we already found another large gap...
                if (gap > 2 * mid + 1 || largeGapsCount > 1) {
                    colorFails = true;
                    break;
                }
            }
            prev = pos;
        }

        // If this specific color found a way to cross, return true immediately
        if (!colorFails) return true;
    }

    return false;
}

bool canCrossInLessThanEqualToMidJumps(int maxAllowedJump, vector<vector<int>> &colorIndices, int n){

    int k = colorIndices.size() -1;
    int extraColorsUsed = 0;
    bool isPossible = false;

    for(int i = 1; i <= k; i ++){

        bool isPossibleForColori = true;
        extraColorsUsed = 0;

        for(int j = 0; j < colorIndices[i].size(); j ++){

            int index = colorIndices[i][j];
            int jumpSize  = 0;

            int preIndex = (j > 0 ) ? colorIndices[i][j-1] : 0;
            jumpSize = index - preIndex -1;

            if(jumpSize <= maxAllowedJump) continue;
            
            if( jumpSize > maxAllowedJump){
                if( jumpSize > (2* maxAllowedJump + 1) || (extraColorsUsed > 1) ){
                    isPossibleForColori = false;
                    break;
                }
                else extraColorsUsed++;
            }
        }

        int lastIndex = (colorIndices[i].size() ) ? colorIndices[i].back() : n;

        int jumpSize = n - lastIndex;
            
        if( jumpSize > maxAllowedJump){
            if( jumpSize > (2* maxAllowedJump + 1) || (extraColorsUsed > 1) ) isPossibleForColori = false;

            else extraColorsUsed++;
        }

        if( extraColorsUsed > 1) isPossibleForColori = false;
        if(isPossibleForColori ) isPossible = true;
    }

    return isPossible;
}

void solve(){

    int n, k;
    cin >> n >> k;

    vector<int> colors(n+1);

    vector<vector<int>> colorIndices(k+1);
    for(int i = 1; i <= n; i ++){
        cin >> colors[i];
        // color present at each index
        // xolors[i]  : [1.. k]
        // color ck -> 1, 4, 6
        colorIndices[colors[i]].push_back(i);
    }

    // max no of planks skipped with one coloring allowed
    int low = 0;
    int high = n;

    int mid;

    int minJumps = n;

    while( low <= high){
        mid = (high + low )/2;

        // check if possible to make a jump of <= mid size and cross the river from 0 to n+1 index
        // as the jump size increases, the girl can cross the river easily
        bool canCrossInMaxMidJumps = canCrossInLessThanEqualToMidJumps(mid, colorIndices, n);

        if( canCrossInMaxMidJumps){
            high = mid - 1;
            minJumps = mid;
        }
        else {
            low = mid +1;
        }
    }


    cout << minJumps << "\n";
    return;
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