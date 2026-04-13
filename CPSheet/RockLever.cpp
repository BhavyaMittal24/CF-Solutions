#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    // no of bits = loog2n + 1;
    cin >> n;

    long long ans = 0;

    vector<int> arr(n);

    // mp storign the cnt of numbers having the same MSB
    // msb -> cnt
    map<int,int> mp;
    for(int i = 0; i < n; i ++){
        cin >> arr[i];
        int msb = log2(arr[i]);

        if(mp.count(msb) == 1){
            ans += mp[msb];
        }

        mp[msb]++;
    }

    cout << ans << "\n";
    return;
}

int main(){

    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while(t--){
        solve();
    }
    return 0;
}