#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n, m;
    cin >> n >> m;

    vector<int> arr(n);

    set<int> vis;
    map<int,int> mp;

    for(int i = 0; i < n; i ++) {
        cin >> arr[i];

        int key = arr[i] % m;
        mp[key] ++;
        // remainder % m -> cnt;
    }

    int ans = 0;

    for(auto it : mp){

        int remainder1 = it.first;
        int freq1 = it.second;

        if(vis.count(remainder1) == 1) continue;
        // key "m - remainder1" exists

        if(mp.count(m - remainder1) == 1){
            int freq2 = mp[m-remainder1];

            if(freq1 > freq2) {
                swap(freq1, freq2);
            }

            // freq1 <= freq2
            ans ++;
            freq2 = freq2 - 1 - freq1;

            if(freq2 > 0 ) ans += freq2;

            vis.insert(m-remainder1);
        }

        else {

            if(remainder1 == 0) ans ++;
            else ans += freq1;
        }
    }

    cout << ans << "\n";
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