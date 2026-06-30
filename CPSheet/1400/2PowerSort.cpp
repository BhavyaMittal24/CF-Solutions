#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);

    for(int i = 0; i < n; i ++){
        cin >> arr[i];
    }

    int l = 0;
    int r = 1;
    int cnt = 0;

    while( l <= r && r < n){

        if( arr[r] > arr[r-1]/ 2 ){

            // this r can be also included as a part : r-1 r]
            if( r - l== k){
                cnt++;
                l++;
            }
        }
        // [r-1 r] false : [r start fresh from here] : [r, r+1]
        else{
            l = r; // move l to r reset the subarray we want to consider ai ai+1 .... ai+k ai+k+1
        }

        r++;
    }

    cout << cnt << "\n";
}
int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}