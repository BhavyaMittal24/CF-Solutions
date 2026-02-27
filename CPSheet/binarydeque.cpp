#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n, s;
    cin >> n >> s;
    vector<int> arr(n);

    int total_Sum = 0;
    for(int i = 0; i < n; i ++) {
        cin >> arr[i];
        total_Sum += arr[i];
    }

    // find the longest window in the array where the sum = s;
    // sum <= k : largest window : use this technique

    if(total_Sum < s) {
        cout << "-1 \n";
        return;
    }

    int sum = 0;
    int left = 0;
    int right = 0;

    int maxlen = 0;
    while(right < n){

        sum += arr[right];
        while(left <= right && sum > s){
            sum -= arr[left];
            left++;
        }
        if(sum == s){
            maxlen = max(maxlen, right-left+1);
        }
        right++;
    }

    cout << n - maxlen << "\n";
    return;
}


// sum on the subarray
int minOperations(int i, int j, int sum , int & s, vector<int> &arr,  vector<vector<vector<int>>>& dp){
    // min op required to make the sum as s
    if( sum == s) {
        return 0;
    }

    // sum made from the subarray if less than desired sum 's', you can't make s no matte how many element you remove
    if( (i > j) || (sum < s)) return INT_MAX;

    if(dp[i][j][sum] != -1) return dp[i][j][sum];

    int removeLeft = INT_MAX;

    if(arr[i] == 1){
        removeLeft= minOperations(i+1, j, sum-1, s, arr, dp);
    }
    else{
        removeLeft = minOperations(i+1,j,sum, s, arr, dp);
    }

    // if immpossible to remove and get sum = s 
    if(removeLeft != INT_MAX) removeLeft ++;

    int removeRight = INT_MAX;

    if(arr[j] == 1){
        removeRight = minOperations(i, j-1, sum-1, s, arr, dp);
    }
    else {
        removeRight = minOperations(i, j-1, sum, s, arr, dp);
    }

    if(removeRight != INT_MAX){
        removeRight ++;
    }

    return dp[i][j][sum] = min(removeRight, removeLeft);
}

void solve2(){

    int n, s;
    cin >> n >> s;
    vector<int> arr(n);

    int totalSum = 0;
    for(int i = 0; i< n; i ++){
        cin >> arr[i];
        totalSum += arr[i];
    }

    if(totalSum < s) {
        cout << "-1 \n";
        return;
    }

    vector<vector<vector<int>>> dp(n, vector<vector<int>> (n, vector<int> (n+1, -1)));
    
    int minOp = minOperations( 0, n-1, totalSum, s, arr, dp);

    minOp = (minOp == INT_MAX) ? -1 : minOp;

    cout << minOp << "\n";
    // for(int i = 0 ; i < n; i ++){
    //     for(int j = 0; j < n; j ++){
    //         for(int sum = 0; sum < n; sum ++){
    //             cout << i << " " << j << " " << sum << " " << dp[i][j][sum] << endl; 
    //         }
    //     }
    // }
    // cout << "\n";
    // dp[i][j][k] 
    // i > j : INT_MAX
    // k < s : INT_MAX : 
    // i<=j and k = s, 0

}

int main(){

    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while(t--){
        solve2();
    }
    return 0;
}