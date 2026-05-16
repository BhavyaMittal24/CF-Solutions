#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    cin >> n;

    long long totalSum = 0;
    vector<int> arr(n+1,0);

    vector<long long> prefixSum(n+1,0);
    for(int i = 1; i <= n; i ++) {
        cin >> arr[i];
        prefixSum[i] = arr[i] + prefixSum[i-1];
    }

    // totalSUm > max subarray sum in the array with length <= n-1

    // l to r : prefixSUm "
    
    // left + 1 : right : : right -left : 
    int minLeft = 0;
    long long maxSubSum = -1e18;
    for(int right = 1; right <=n; right ++){

        //cout << minLeft << " " << right << " " << "\n";
        //cout << prefixSum[minLeft] << prefixSum[right] << "\n";
        if( (right - minLeft) == n){
            minLeft++;
        }
        long long currWindowSum = prefixSum[right] - prefixSum[minLeft];
        maxSubSum = max(maxSubSum, currWindowSum);

        //  prefix : ... 15 , 35m 45m .... 35 .... 35 : makes sense to use the last 35 index
        if( prefixSum[right] <= prefixSum[minLeft]){
            minLeft = right;
        }

    }

    //cout << prefixSum[n] << "  " << maxSubSum << "\n";
    if(prefixSum[n] > maxSubSum){
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }

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