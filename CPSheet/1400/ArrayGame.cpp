#include<bits/stdc++.h>
using namespace std;

//long long minValue = 1e18+1;

long long minValueOverK(int i, vector<long long> &arr, int k, long long minValSoFar){

    //cout << i << " " << k << " " << minValSoFar << "\n";
    if(i >= k){
        // n + k length of array
        return minValSoFar;
    }

    // find all the differences;
    long long minValTillI = 1e18 +1;
    //vector<long long> diff;

    for(int j = 0; j < arr.size(); j ++){

        for(int l = j+1; l < arr.size(); l ++){
            // j and k are the two differences
            long long d = abs(arr[j] - arr[l]);

            arr.push_back(d);
            long long minValOptions = minValueOverK(i+1, arr, k, min(minValSoFar, d));
            minValTillI = min(minValTillI, minValOptions);
            arr.pop_back();
        }
    }
    return minValTillI;
}

void solve(){

    int n, k;
    cin >> n >> k;

    vector<long long> arr(n);

    long long minValSoFar = 1e18 +1;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        minValSoFar = min(minValSoFar, arr[i]);
    }
    // 1 <= arri <= 1e18
    // k <= 1e9 opeations 
    // n2 < 1e6

    // 1 to n minValSoFar
    long long minVal = minValueOverK(0,arr,k, minValSoFar);

    cout << minVal << "\n";
}

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}