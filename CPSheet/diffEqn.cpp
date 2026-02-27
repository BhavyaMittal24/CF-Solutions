#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    cin >> n;
    
    vector<long long> arr(n+1,0);

    for(int i =1; i <= n; i ++) cin >> arr[i];

    int x = n-2;
    int y = n-1;
    int z = n;

    vector<vector<int>> ans;
    // arr should be non dec : increasing
    // x < y < z
    // arr[x] <= arr[y] <= arr[z]
    if(arr[z] < arr[y]) {
        cout << "-1\n";
        return;
    }

    bool isNotPossible = false;

    while(x >= 1){

        if(arr[x] <= arr[y]) {
            x--;
            y--;
            continue;
        }
        // arr[x] > arr[y];

        long long newVal = arr[y] - arr[z];
        if( newVal <= arr[y] ){
            arr[x] = newVal;
            ans.push_back({x, y , z});
            x--;
            y--;
            continue;
        }
        else {
            isNotPossible = true;
            break;
        }
    }

    if(isNotPossible){
        cout << "-1\n";
        return;
    }

    cout << ans.size() << "\n";

    for(int i = 0 ; i < ans.size(); i++){
        for(auto idx : ans[i]){
            cout << idx << " ";
        }
        cout << "\n";
    }
    
    return;
}
int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}