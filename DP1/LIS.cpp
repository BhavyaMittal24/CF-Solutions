#include<bits/stdc++.h>
using namespace std;

// returns the LIS for arr startign from i to n-1 where previous element is v
int LIS(int i, int v, vector<int> &arr, vector<vector<int>> &dp){
    if( i == arr.size()) return 0;

    if(dp[i][v] != -1) return dp[i][v];

    int take = 0;
    if( arr[i] > v){
        take = 1 + LIS(i+1,arr[i],arr,dp);
    }

    int notTake = LIS(i+1,v,arr,dp);
    return dp[i][v] = max(take, notTake);
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    
    int maxN = 0;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        maxN = max(arr[i], maxN);
    }

    vector<vector<int>> dp(n, vector<int>(maxN+1, -1));
    cout << LIS(0, 0,arr, dp) << endl;

}