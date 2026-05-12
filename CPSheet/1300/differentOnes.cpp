#include<bits/stdc++.h>
using namespace std;


void solve(){

    int n;
    cin >> n;
    vector<int> arr(n+1,0);

    vector<int> prevDifference(n+1,0);
    for(int i = 1; i <= n; i ++){
        cin >> arr[i];
        if( i == 1 ) {
            prevDifference[i] = -1;
            continue;
        }

        if( arr[i] == arr[i-1] ) {
            prevDifference[i] = prevDifference[i-1];
            // 1 1
            // 0 1 
        }
        else {
            prevDifference[i] = i-1;
            // i-1 , i : arr[i] != arr[i];
        }
    }

    int q;
    cin >> q;

    // 1 1 2 1 1
    
    //     r
    // 1 1 1 

    vector<pair<int,int>> ans;
    while(q--){
        int l, r;
        cin >> l >> r;

        if( l== r){
            ans.push_back({-1,-1});
            continue;
        }

        int index = prevDifference[r];
        if( prevDifference[r]  == -1){
            ans.push_back({-1,-1});
        }

        // 30 20 20 10 10 20

        // -1 1  1  3  3  4

        // 1 2
        // 2 3
        // 2 4
        // 2 6
        // 3 5

        // 2 4
        // else if(index == -1){
        //     ans.push_back({1,r});
        // }
    
        // 10 20
        // -1 1
        else if( index < l){
            ans.push_back({-1,-1});
        }

        // index >= l && index != -1 && prevDiff[r] != -1
        else  {
            ans.push_back({index, r});
            //cout << index << " " << r << "\n";
        }
    }

    for(auto it : ans){
        cout << it.first << " " << it.second << "\n";
    }
    cout << "\n";

    return;
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