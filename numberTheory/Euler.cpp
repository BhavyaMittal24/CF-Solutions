#include<bits/stdc++.h>
using namespace std;

long long mod = 1e9+7;

// Function to compute (base^exp) % mod using binary exponentiation

//base^exp % mod

// o(log(exp))
long long binaryExponentation(long long base, long long exp, long long mod){
    long long res = 1;

    // base^exp
    // exp = 2 : 1
    while(exp>0){
        if(exp & 1){
            res = (res * base) % mod;
        }
        base = (base*base) % mod;
        // right shift the bits of exp ny 1 to eleminate the last bit
        exp = exp >> 1;
    }
    return res;
}

int main(){
    int t;
    cin >> t;
    while(t--){
    long long a,b,c;
    cin >> a >> b >> c;
    long long x = binaryExponentation(b,c,mod-1);
    long long ans = binaryExponentation(a,x,mod);
    cout << ans << endl;
    }
    return 0;
}