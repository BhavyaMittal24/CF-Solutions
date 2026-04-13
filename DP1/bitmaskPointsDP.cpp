#include<bits/stdc++.h>
using namespace std;


/*
Given a list of n points, find the arrangement/ rearrange the points in such a way that the sum of distance between adjacent points is minimum
p0 , p1, p2, p3, p4, p5 .... pn-1

      i, {set of points already taken} , prevIndex

      for(int point = 0; point <= n; point ++){
        if(the point is free and not already taken)
        dp[i][mask][prev] = (prev == 0) ? 0 : dis(prev, point) + dp[i+1][mask | (1<< (point-1))]
        // find the min value
      }

      dp[mask][prevIndex]

      final ans : dp[0][0][0];
*/


int findDis(pair<int,int>& a, pair<int,int> &b){

    return abs(a.first - b.first) + abs(a.second - b.second);
}
int main(){


    int n;
    cin >> n;

    vector<pair<int,int>> points(n);

    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;

        points[i] = {x,y};
    }

    // find the min sum of distance between all adjacetn points

    //dp[mask][prev] : min sum of adj distances when these many set bits are already incliuded and prev index is prev
    vector<vector<int>> dp(1<<n, vector<int> (n+1, 1e9));

    // dp[(1<<n) - 1][anythinh] = 0 : all bits are set : all points are taken 
    for(int i = 0; i <=n; i ++) {
        dp[(1<<n) - 1][i] = 0;
    }

    for(int mask = (1 << n) - 2; mask >= 0; mask --){

        for(int prev = 0; prev <= n; prev ++){

            // prev == 0 : no ppoint is previous to the current point
            // point = 1 : regers to the 0th index
            for(int point = 1; point <= n; point ++){

                // enmsure that this point is not set in the mask : I can add this point index to my mask
                if ( ( mask & (1 << (point-1)) )  == 0 )
                {
                    int val = (prev == 0) ? 0 : findDis(points[point-1], points[prev-1]);
                    dp[mask][prev] = min( dp[mask][prev], val + dp[mask | (1 << (point-1))][point] );
                }

            }

        }
    }

    cout << dp[0][0] << "\n";
    return 0;
}