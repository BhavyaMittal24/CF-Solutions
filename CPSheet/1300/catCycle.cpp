#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n, k;
    cin >> n >> k;
   
    // n spots .. k hours b location
    // b = 1
    // a = n

    if( n % 2 == 0){
        // even they will nver intersect

        // kth jour ; k-1 steps
        int b = 1 + (k-1) % n;
        cout << b << "\n";
        
    }

    else {

        // whether they will intersect or not that that k

        // (k - 1) % (n/2) = 0
        if( (k - 1 ) % (n/2) == 0){
            //after n/2 +1 times there is  a cycle : cyclicity of n/2 + 1 times

            int a = n - (k-1) % n;
            int b = a + 1;
            if( b == n+1) b = 1;
            cout << b << '\n';
        }

        else {
            // give b's location

            int factor = (k-1) / (n/2);
            int k1 = factor * (n/2) + 1;
            // we clash at k1

            int a = n - (k1-1) % n;
            int b = a + 1;
            if( b == n+1) b = 1;

            int diff = k - k1;
            b = b + (diff % n);

            
            int b = 1 + (k-1 + factor) % n;
            cout << b << "\n";
        }
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