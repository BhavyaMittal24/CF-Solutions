#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++) cin >> arr[i];

    int x;
    cin >> x;
    sort(arr.begin(), arr.end());
    if( x >= arr[0] && x <= arr[n-1] ) cout << "YES" << endl;
    else cout << "NO" << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}