#include<bits/stdc++.h>
using namespace std;

void solve(){
    int s, k , m;
    cin >> s >> k >> m;

    int waitTime = 0;
    if( s <= k){

        waitTime = s - (m % k);
        waitTime = max(0, waitTime); 
    }
    // s > k

    else {
        int sand = s;
        int val = (m / k);
        if( val % 2 == 0){
            sand = s;
        }
        else {
            sand = k;
        }
        waitTime = max(0, sand - (m % k));
    }

    cout << waitTime << endl;
    return;
}
int main(){
    int t;
    cin >>t;
    while(t--){
        solve();
    }
    return 0;
}