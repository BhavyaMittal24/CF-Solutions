#include<bits/stdc++.h>
using namespace std;

// prevDishNumber from 1 to n

int cntSetBits(int mask){

    int cnt = 0;
    for(int i = 0; i <= 18; i ++){

        if ( ( mask & (1 << i)) != 0 ){
            cnt++;
        }
    }

    return cnt;
}

// dp[i][mask][currDish]  : currDish is not in the mask of taken dishes : 
// we select nextDish such that it is not same as currDish and mask wil have currDish also in it

// dp[set of values already selected upot length m][prevish index from 1 to n]
long long maxSatisfaction(int idx, int mask, int currDish, int& m, int& n, vector<vector<int>>& keyValue, vector<vector<long long >>& dp, vector<int> & a){


    if(idx >= m-1) return 0;

    // int set_bits = cntSetBits(mask);

    //if (( mask  & (1 << currDish) ) != 0 ) return 0;

    if(dp[mask][currDish] != -1) return dp[mask][currDish];


    long long ans = 0;

    long long tempAns = 0;
    for(int nextDish = 0; nextDish < n; nextDish ++){


        if(nextDish == currDish) continue;

        // only if the nexDish is not taken up before
        if(  (mask & (1 << (nextDish)) ) == 0 ) {

            //string key = to_string(prev) + "#" + to_string(currDish);
            int newMask = mask |  (1 << (nextDish));

            if(keyValue[currDish][nextDish] == -1){
                tempAns =  1ll* a[nextDish] + maxSatisfaction(idx+1, newMask, nextDish, m, n,keyValue,dp, a);
            }
            else {
                tempAns = 1ll*keyValue[currDish][nextDish] + 1ll* a[nextDish] + maxSatisfaction(idx+1, newMask, nextDish, m, n,keyValue,dp, a);
            }

            ans = max(ans, tempAns);
        }
    }

    return dp[mask][currDish] = ans;
}

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n, 0);

    // dishes from 0 to n
    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }

    vector<vector<int>> keyValue(19, vector<int>(19,-1));

    for(int i = 0; i < k; i ++){
        int u, v, c;
        cin >> u >> v >> c;

        keyValue[u-1][v-1] = c;
    }


    // dp[2^n][prev]

    // dp[mask][prev] 

    long long ans = 0;
    
    vector<vector<long long >> dp( (1<<n) , vector<long long> (n+1, -1));

    for(int i = 0; i < n; i ++){
        ans  = max (ans, 1ll*a[i] + maxSatisfaction(0,1<<i,i,m,n, keyValue, dp, a));
    }

    cout << ans << "\n";

    return 0;
}