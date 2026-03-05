#include<bits/stdc++.h>
using namespace std;

long long mod = 1e9 + 7;
long long ans(int n , int k ){

    long long ans = 1;

    for(int i = 0; i < k; i++){

        ans = (1ll* ans * n) % mod;
    }
    return ans;
}
void solve(){

    int n, k;
    cin >> n >> k;

    cout << ans(n,k) << "\n";
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