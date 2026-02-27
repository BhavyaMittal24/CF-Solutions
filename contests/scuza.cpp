#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n, k;
    cin >> n >> k;

    vector<long long> pre(n);

    vector<int> arr(n);
    vector<int> maxHeight(n,0);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if(i == 0){
            pre[0] = arr[0];
            maxHeight[i] = arr[i];
        }
        else {
            maxHeight[i] = max(maxHeight[i-1], arr[i]);
            pre[i] = pre[i-1] + arr[i];
        }
    }

    vector<int> queries(k);
    for(int i = 0; i < k ; i ++){
        cin >> queries[i];
        // find the first index which has a value >= the height ki : if the maxHeight is <= the height ki, cout it's prefix value;

        auto it = upper_bound(maxHeight.begin(), maxHeight.end(), queries[i]);
        // returns the iterator 
        long long ans = 0;
        it = it -1;
        if(it >= maxHeight.begin() && *it <= queries[i]){
            int stepIdx = it - maxHeight.begin();
            ans = pre[stepIdx];
        }
        cout << ans << " ";
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}