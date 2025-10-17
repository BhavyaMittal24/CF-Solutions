#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> arr(m);
    for(int i=0;i<m;i++){
        cin >> arr[i];
    }

    int ans = 1;

    for(int i=0;i<m-1;i++){
        if(arr[i] >= arr[i+1]){
            cout << ans << endl;
            return;
        }
    }

    ans = n-arr[m-1]+1;
    cout << ans << endl;
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