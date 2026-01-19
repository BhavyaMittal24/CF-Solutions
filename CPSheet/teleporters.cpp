#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long n, c;
    cin >> n >> c;

    vector<long long> arr(n+1);

    for(int i = 1; i <= n ; i ++){
        int x;
        cin >> x;
        arr[i] = i + x;
    }

    sort(arr.begin(), arr.end());

    int tele = 0;

    long long sum = 0;
    for(int i = 1; i <= n ; i ++){
        sum += arr[i];
        if( sum <= c) tele ++;
        else break;
    }

    cout << tele << "\n";
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