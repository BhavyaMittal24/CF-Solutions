// n coins n : odd : find probability of getting more heads than tails

#include<bits/stdc++.h>
using namespace std;


// precision = 1e9
int main(){

    int n;
    cin >> n;
    // dp[i][h] : for a length i, prob of no of heads = h
    vector<vector<double>> dp(n+1,vector<double>(n+1,0.0));

    // base cases : dp[0][anything] = 0.0
    // when  h > i , dp[i][h] = 0.0
    
    vector<double> p(n,0.0);
    for(int i=0;i<n;i++){
        cin >> p[i];
    }

    dp[1][0] = 1 - p[0];
    dp[1][1] = p[0];

    // recurrence relation :
    // prob to get h heads in i coin tosses = prob of getting head in ith coin toss * prob of getting h-1 heads in i-1 tosses + prob of getting tail in ith coin toss * prob of getting h heads in i-1 tosses 
    // dp[i][h] = p[i-1] * dp[i-1][h-1] + (1 - p[i-1]) * dp[i-1][h];

    // final ans : prob of getting more than n/2 heads in n tosses
    // sum of p[n] [x] x >= n+1 / 2

    for(int i=2;i<=n;i++){
        for(int h=0;h<=i;h++){
            if(h == 0){
                dp[i][h] =  (1-p[i-1]) * dp[i-1][h];
                continue;
            }
            dp[i][h] = p[i-1] * dp[i-1][h-1] + (1 - p[i-1]) * dp[i-1][h];
        }
    }

    double ans = 0.0;
    for(int h=(n+1)/2;h<=n;h++){
        ans += dp[n][h];
    }
    cout << fixed << setprecision(9) << ans << endl;
    return 0;
}
