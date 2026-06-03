#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    cin >> n;
    vector<int> arr(n,0);

    for(int i = 0; i < n; i ++) cin >> arr[i];

    int cnt = 0;

    if( arr.back() > 0) cnt++;

    long long previousSum = arr.back();
    for(int j = n-2; j >= 0; j --){

        if(previousSum < 0) previousSum = 0;

        if( 1ll*arr[j] + previousSum > 0) {
            cnt++;
        }

        previousSum = 1ll*arr[j] + previousSum;
    }

    cout << cnt << "\n";
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