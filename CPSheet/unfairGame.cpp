#include<bits/stdc++.h>
using namespace std;

long long ncr(int n, int r){
    // n! / (n-r)! * r!
    // n * n-1 * n-2 * ... n-(r-1) 

    long long num = 1;
    long long den = 1;
    for(int i = 0; i <= r-1 ; i ++){
        num  = 1ll * num * (n-i) / (i+1);
    }

    return num / den;
}

long long expo(int base , int exp){
    long long ans = 1;
    while(exp--){
        ans = 1ll* ans * base;
    }
    return ans;
}

void solve(){

    int n, k;

    cin >> n >> k;
    int m = log2(n);

    long long cnt = 0;

    // x = 1 : k = 1
    for(int x = m; x >= 1; x --){

        if ( ( 1 << x) > n ) continue;

        if( x + 1 > k) {
            
            if( (1 << x) == n) cnt++;
            
            else {
                cnt += expo(2,x);
            }
        }

        else {
            // some space for out of x bits, we can have (k-x bits set : equal to no of operarions more k +1 - (x+1)) 
            // no of ways to select bits such that atleast k-x out of x are 1 : atleast 3 out of 5 should be 1
            if( (x >= k -x) && ( (1 << x) != n) ){
                
                long long ans = 0;
                for(int i = 0; i <= 2*x -k; i ++){
                    ans += ncr(x, k - x + i);
                }
                cnt += ans;
            }
        }
    }

    //cout << ncr(5,2) << " " <<  expo(2,4) << "\n";

    cout <<  cnt << "\n";
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