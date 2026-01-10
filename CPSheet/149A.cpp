#include<bits/stdc++.h>
using namespace std;

void solve(){

    int x, k;
    cin >> x >> k;

    // if( x < k){
    //     cout << 1 << endl;
    //     cout << x << endl;
    // }

    if( x % k ){
        cout << 1 << endl;
        cout << x << endl;
        return;
    }

    // x  p1 p2 p3 p4
    // k  p`1 p`2 p`3 .. 
    // for x to be divisble perfectly by k : all the pf should be the same or atleast for the factors present in k should also be present in x

    cout << 2 << endl;
    cout << x - k +1 << " " << k -1 << endl;
}
int main(){

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}