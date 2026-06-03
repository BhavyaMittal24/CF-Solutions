#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int uid(int a, int b) { return uniform_int_distribution<int>(a, b)(rng); }
ll uld(ll a, ll b) { return uniform_int_distribution<ll>(a, b)(rng); }

void solve(){
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    int l = 0, r = 1e9 + 5;
    while (l < r){
        int mid = (l + r) / 2;

        int one = 0, zero = 0;
        int prev = -1;
        for (int i = 0; i < n; i++){
            int type = 0;
            if (a[i] >= mid)
                type++;
            if (b[i] >= mid)
                type++;

            if (type == 1)
                continue;

            if (type == 2){
                one++;
                prev = 1;
            }

            if (type == 0){
                if (prev != 0)
                    zero++;
                prev = 0;
            }
        }

        if (one > zero)
            l = mid + 1;
        else
            r = mid;
    }

    cout << l - 1 << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) solve();
}
