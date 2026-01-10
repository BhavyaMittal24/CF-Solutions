#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;
void solve(){

    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);

    for(int i = 0 ; i < n ; i ++){
        cin >> a[i];
    }

    for(int j = 0; j < n ; j++){
        cin >> b[j];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());


    long long ans = 1;
    for(int i = n-1; i >= 0 ; i --){

        int bi = b[i];
        // look for all the values of a[i] bigger than bi
        int cntAGreaterThanB = 0;
      
        auto it = lower_bound(a.begin(), a.end() , bi+1);
        
        cntAGreaterThanB = it - a.begin();
        cntAGreaterThanB = n - cntAGreaterThanB;
        
        ans =  ( ans * (cntAGreaterThanB - (n-1 - i)) ) % mod;
    }

    cout << ans <<endl;
}
int main(){

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}