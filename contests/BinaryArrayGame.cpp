#include<bits/stdc++.h>
using namespace std;


void solve(){

    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i ++){
        cin >> arr[i];
    }

    if(arr[0] == 1 || arr[n-1] == 1){
        cout << "ALICE" << endl;
    }
    else {
        cout << "BOB" << endl;
    }
    return;
}
int main(){

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}