#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9+7;

long long binaryExp(long long base, long long exp){
    base = base % mod;
    long long ans = 1;
    while(exp){
        if(exp & 1){
            ans = (ans * base) % mod;
        }
        base = (base * base) % mod;
        exp = exp >> 1;
    }
    return ans;
}
int main(){

    int n,m;
    cin >> n >> m;

    long long first = binaryExp(2,m);
    first = (first -1 + mod) % mod;

    long long ans = binaryExp(first,n);
    cout << ans << endl;
}