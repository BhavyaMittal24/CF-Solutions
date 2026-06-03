#include<bits/stdc++.h>
using namespace std;


void solve(){

    int n;
    cin >> n;
 
    vector<int> arr;
    for(int i = 0; i < n; i ++){
        int x;
        cin >> x;
        arr.push_back(x);
    }

    sort(arr.begin(), arr.end());

    int first = arr[0];
    int last = arr.back();

    int minOp = 1001;

    for(int i = first; i <= last; i ++){

        int maxDiff = 0;
        for(int j = 0; j < n; j ++){

            int diff = abs(i - arr[j]);
            maxDiff = max(maxDiff, diff);
        }
        minOp = min(minOp, maxDiff);
    }

    cout << minOp << "\n";
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