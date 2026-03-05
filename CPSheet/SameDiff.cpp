#include<bits/stdc++.h>
using namespace std;


void solve(){

    int n;
    cin >> n;

    long long cnt = 0;
    map<int,int> mp;

    for(int i = 1; i <= n; i ++){
        int x;
        cin >> x;

        // for the same difference : i and j ; 
        // aj - ai = j - i;
        // ai - i = aj - j
        // all pairs having this one property commom can be considered
        int val = (x - i);
        if(mp.count(val) == 1){
            cnt += mp[val];
        }

        mp[val]++;
    }

    cout << cnt << "\n";
    return;
}
int main(){

    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}