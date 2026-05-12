#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    cin >> n;

    // n :  a + b = n
    // min lcm for a and b. find a and b such that lcm(a,b) = miniumum and a+b = n
    // 1, n-1 : max min lcm
    // a , b : will be minimum only if a and b have some common factors between them : k, n - k : checl for factors of n : a will be a factor having some common factor with b
    // n - k : lcm : i need maximum factor

    int maxFactor = 1;
    for(int i = 2; i * i <= n; i ++){

        if(n % i == 0){
            maxFactor = max(maxFactor, i);
            maxFactor = max(maxFactor, n / i);
        }
    }
    
    cout << maxFactor << " " << n - maxFactor << "\n";
    return;
}
int main(){
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while(t--){
        solve();
    }
    return 0;
}