#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<pair<int,int>> arr(n+1);
    int color = 0;
    for(int i = 1; i <= n; i ++){
        int x;
        cin >> x;
        arr[i] = {x, color};
        color = color ^ 1;
    }

    sort(arr.begin(), arr.end());

    bool isValid = true;
    int prevColor = arr[1].second;
    for(int i = 2; i <= n ; i ++){
        int color = arr[i].second;
        if( color == prevColor) {
            isValid = false;
            break;
        }
        prevColor = color;
    }

    if(isValid) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while(t--){
        solve();
    }
    return 0;
}
