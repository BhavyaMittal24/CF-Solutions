#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 0) {
            cnt0++;
        }
        else if ( x== 1){
            cnt1++;
        } 
        else{
            cnt2++;
        }   
    }

    long long op = 0;

    op += cnt0;

    int pairs = min(count1, count2);
    max_operations += pairs;

    count1 -= pairs;
    count2 -= pairs;

    max_operations += (count1 / 3);

    max_operations += (count2 / 3);

    cout << max_operations << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    } else {
        solve();
    }
    return 0;
}