#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n, x1, x2, k;

    cin >> n >>x1 >> x2 >> k;

    if( n <=3) {
        cout << "1\n";
        return;
    }
    int minTime = 1e9;

    int time1 = abs(x1-x2) + k;
    int time2 = n - max(x1,x2) + min(x1,x2) + k;

    minTime = min(time1, time2);
    cout << minTime << '\n';
    return;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >>t;

    while(t--){
        solve();
    }
    return 0;
}