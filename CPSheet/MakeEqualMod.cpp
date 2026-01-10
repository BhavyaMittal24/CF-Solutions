#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    cin >> n;

    vector<long long> a(n);

    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }

    long long k = 2;

    while( k < 1e18){

        long long val1 = -1;
        long long val2 = -1;

        for(int i = 0; i < n; i ++){
            long long mod = a[i] % k;
            if( val1 == -1) {
                val1 = mod;
            }
            else if(val1 != -1 && mod != val1 ) val2 = mod;
        }

        if(val2 != -1) {
            break;
        }

        k = k * 2;
    }

    cout << k << "\n";
    
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}