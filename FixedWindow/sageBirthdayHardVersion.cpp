#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> arr(n, 0);
    vector<int> ans(n,0);

    for( int i = 0; i < n; i ++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    if( n < 3){
        cout << "0\n";
        for(auto &x : arr){
            cout << x << " ";
        }
        cout << "\n";
        return 0;
    }

    int idx = 1;

    int cnt = (n% 2 == 0 ) ? n/2-1 : n/2;

    vector<int> vis(n, 0);

    int c = 0;
    while(c < cnt){
        ans[idx] = arr[c];
        vis[c] = 1;
        idx += 2;
        c++;
    }
    //     j
    // 1 2 2 2 5
    //   1   2
    int j = cnt;
    idx = 1;

    while( j < n && idx < n){

        while(j < n && arr[j] <= ans[idx]){
            j++;
        }

        if(j < n){ 
            //cout << ans[idx] << " " << arr[j] << "\n";
            ans[idx-1] = arr[j];
            // all the max peaks whcih have been taken
            vis[j] = 1;
        }
        j++;
        idx += 2;
    }

    j = 0;

    for(int i = 0; i < n; i ++){
        while(j < n && vis[j] == 1){
            j++;
        }
        if(ans[i] == 0){
            ans[i] = arr[j];
            j++;
        }
    }

    cnt = 0;
    for(int i = 2; i < n; i ++){
        int mid = ans[i-1];
        int low = ans[i-2];
        int high = ans[i];

        if( low > mid && high > mid) cnt++;
    }

    cout << cnt << "\n";
    for(auto x:  ans){
        cout << x << " ";
    }

    cout << "\n";

    return 0;
}