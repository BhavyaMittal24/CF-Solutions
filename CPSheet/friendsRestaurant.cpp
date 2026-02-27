#include<bits/stdc++.h>
using namespace std;

void solve() {

    int n;
    cin >> n;
    
    vector<int> x(n);
    vector<int> y(n);

    for(int i = 0; i < n ; i ++){
        cin >> x[i];
    }

    for(int i = 0; i < n ; i++) cin >> y[i];

    vector<int> diff(n);

    for(int i = 0; i < n; i ++){
        diff[i] = y[i] - x[i];
    }

    sort(diff.begin(), diff.end());

    int i = 0;
    int j = n-1;

    int cnt = 0;
    while( i < j){

        if( diff[i] + diff[j ] >= 0) {
            i ++;
            j--;
            cnt++;
        }
        else{
            i++;
        }
    }

    cout << cnt << "\n";
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