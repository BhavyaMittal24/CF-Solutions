#include<bits/stdc++.h>
using namespace std;

long long gcd(int a, int b){
    if( b == 0) return a;

    return gcd(b, a % b);
}

void solve(){
    int n, x , y;
    cin >> n >> x >> y;

    int maxValues = n/x;
    int minValues = n/y;

    long long LCM = 1ll * x * y / gcd(x,y);

    int commonValues = n / LCM;

    maxValues -= commonValues;
    minValues -= commonValues;

    
    long long add = 1ll* n * (n+1) / 2;
    long long diff =  1ll* ( n - maxValues) * (n - maxValues + 1) / 2;

    add -= diff;

    long long subtract = 1ll* minValues * (minValues + 1) / 2;

    add -= subtract;
   cout << add << endl;
   return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}