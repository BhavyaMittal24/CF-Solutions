#include<bits/stdc++.h>
using namespace std;

int findCost(int x, int y, int i, int j,  vector<vector<long long>> &rightDistances,  vector<vector<long long>> & downDistances )
{
    // move down / up
    if(y == 0){
        if( x == 1){
            return downDistances[i][j];
        }
        if(x == -1) {
            return downDistances[i-1][j];
        }
    }

    // move right/left only
    else if( x == 0){
        if(y == 1){
            return rightDistances[i][j];
        }
        if( y == -1){
            return rightDistances[i][j-1];
        }
    }
    
}
int main(){

    int n,m,k;
    cin >> n >> m >> k;

    // adject adeges of i,j are
    // i,j -> i+1,j : i-1,j : i, j+1, i, j-1 can move U,D,R,L
    
    vector<vector<long long>>rightDistances(n, vector<long long>(m-1,0));
    vector<vector<long long>> downDistances(n-1, vector<long long>(m,0));

    // i,j : i, j+1
    // move to right
    for(int i=0;i<n;i++){
        for(int j=0;j<m-1;j++){
            cin >> rightDistances[i][j];
        }
    }

    // i,j -> i+1,j
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m;j++){
            cin >> downDistances[i][j];
        }
    }

    // when moving 
    // R : i, j -> i+1, j  : +rightDistance[i][j];
    // L : i,j -> i-1, j   : +rightDistance[i][j-1]
    // D : i,j -> i+1,j : +downDistance[i][j]
    // U : i,j -> i-1, j : +downDistance[i-1][j];

    // for k = odd, the answer will be always -1 : not possible to reach cyclically back to i,j from i,j

    // dp[i][j][k] : min sum to reach i,j from i,j in k steps

    // base case : dp[i][j][0] = 0; // in 0 steps you will be back at same place

    // dp[i][j][k% 2 == 1] = -1; 

    // dp[i][j][k] = min( if( i+1,j != -1) 2x1 + dp[]..).. k-2

    // dp[i][j][k] -> dp[i][j+1][k-2] dp[i][j-1] dp[i+1][j]]
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(m, vector<int> (k+1,0)));

    for(int l=1;l<=k;l++){

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // for odd steps, you cant ever return to the saeme i,j
                if( l %2  == 1){
                    dp[i][j][l] = -1;
                    continue;
                }

                vector<int> X = {1,-1,0,0};
                vector<int> Y = {0,0,1,-1};
                // {1,0} , {-1,0} , {0,1} , {0,-1}
                int minValue = INT_MAX;
                for(int r = 0;r<4;r++){
                    int newX = i + X[r];
                    int newY = j + Y[r];
                    if( newX >= 0 && newX < n && newY >=0 && newY < m && l >= 0 && dp[newX][newY][l-2] != -1){
                        int cost = findCost(X[r], Y[r], i,j, rightDistances, downDistances);
                        minValue = min(minValue, 2* cost + dp[newX][newY][l-2]);
                    }
                }
                
                if(minValue == INT_MAX){
                    dp[i][j][l] = -1;
                }
                else dp[i][j][l] = minValue;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << dp[i][j][k] << " ";
        }
        cout << endl;
    }
    return 0;
}