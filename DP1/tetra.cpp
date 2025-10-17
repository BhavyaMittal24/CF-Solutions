// no of ways to go from current state to D in the given no of steps



// dp[state][steps] = no of ways to go from state to D in steps

#include <bits/stdc++.h>
using namespace std;


const long long mod = 1e9 + 7;


// length of steps = n

// so using n operations we have to go from D to D

// D -> A ->  B

//     -> B -> D,A,C

//      C   A,B,D

int main(){

    // dp[state][steps] = no of ways to go from state to D  and steps taken so far = steps 

    // dp[A][steps] = dp[B][steps+1] + dp[C][steps+1] + dp[D][steps+1]

    // base case :

    // dp[D][n] = 1

    // dp[anything][n] = 0;

    int n;
    cin >> n;
    //vector<vector<long long>> dp(4, vector<long long>(n + 1, -1));

    vector<long long> prev(4,0);
    vector<long long> curr(4,0);
    
    prev[3] = 1; // dp[D][n] = 1

    for(int steps = n-1; steps >= 0; steps--){

        for(int state = 0; state < 4; state++){

            long long ways = 0;

            for(int nextState = 0; nextState < 4; nextState++){

                if(nextState == state) continue;

                ways = (ways + prev[nextState]) % mod;
            }

            curr[state] = ways;
        }
        prev = curr;
    }
    
    cout << curr[3] << endl;


}