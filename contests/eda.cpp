#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin >> n;
    int rem = n % 3;
    int ans = 0;
    if(rem == 1){
        ans = 2;
    }
    else if(rem == 2){
        ans = 1;
    }
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}