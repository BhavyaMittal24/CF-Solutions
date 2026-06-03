#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n, k;
    cin >> n >> k;

    vector<long long> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    if( k>= 3){
        cout << "0\n";
        return;
    }

    sort(arr.begin(), arr.end());
    
    // diff array size : of n * n-1 /2
    vector<long long> diff;

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            // diff
            long long d = abs(arr[i] - arr[j]);
            diff.push_back(d);
        }
    }

    sort(diff.begin(), diff.end());
    // k == 1, 2

      // k == 2 : 2 elements : 
    // for each di , find the next di+1 closest in the array ai
    long long minDiff = diff[0];

    for(int i = 0; i < n; i ++){
        minDiff = min(minDiff, arr[i]);
    }

    if( k == 1){
        cout << minDiff << "\n";
        return;
    }

  

    // place all di at the n+1th index and then check which one will have closest value to ai, and then find that difference
    // di -> check all , and then next difference will be di - ax : closest ax
    for(int i = 0; i < diff.size(); i++){

        // find the closest value to di in the array
        // first value >= x : lower_bound
        auto it = lower_bound(arr.begin(), arr.end(), diff[i]);
        
        if( it!= arr.end()) minDiff = min(minDiff, 1ll*abs(*it - diff[i]));

        // >= x : first iterator which has the value >= x .. 1,3,4.. x, x+1..  : returns x
        
        if( it!= arr.begin()) {
            it--;
            minDiff = min(minDiff, 1ll*abs(diff[i] - *it));
        }
    }
    cout << minDiff << "\n";
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