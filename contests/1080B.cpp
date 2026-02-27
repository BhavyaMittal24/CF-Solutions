#include<bits/stdc++.h>
using namespace std;


void solve(){

    int n;
    cin >> n;
    
    vector<int> arr(n+1,0);
    for(int i = 1; i <=n; i ++) {
        cin >> arr[i];
    }

    bool isPossible = true;
    for(int i = 1; i <= (n/2); i ++){
        int minidx = 2*i;
        for(int j = 2*i; j <= n; j = j *2){
            if( arr[j] < arr[minidx]){
                minidx = j;
            }
        }
        if(arr[minidx] < arr[i] ) swap(arr[i], arr[minidx]);
    }

    for(int i = 1; i <=n ; i ++){
        if(arr[i] != i) {
            isPossible = false;
            break;
        }
    }
    if(isPossible) {
        cout << "YES\n";
    }
    else cout << "NO\n";

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