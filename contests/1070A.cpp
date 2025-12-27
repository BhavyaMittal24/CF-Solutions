#include<bits/stdc++.h>
using namespace std;


void solve(){

    int n;
    cin >> n;
    vector<int> arr(n,0);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    int cnt = 0;
    for(int j = n-1 ; j >= 1; j --){
        for(int i = j-1; i >= 0 ; i--){
            int aj = arr[j];
            int ai = arr[i];
            if(ai > aj) {
                cnt ++;
                break;
            }
        }
    }

    cout << cnt << endl;
}

int main(){

    int t;
    cin >> t;
    while(t--){
        solve();
    }
}