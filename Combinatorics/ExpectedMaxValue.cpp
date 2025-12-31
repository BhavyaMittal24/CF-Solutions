#include<bits/stdc++.h>
using namespace std;

//const long long mod = 1e9 +7;

long long binaryExp( long double base, long long exp){

    long double ans = 1;

    //base =  ( base % mod );

    while( exp > 0){

        if( exp & 1){
            ans = (ans * base);
        }
        base = (base * base) ;
        exp = exp >> 1;
    }

    return ans;
}
int main(){

    int n, m;

    cin >> m >> n;

    long double num = 0;

    for( int i = 1; i <= m ; i ++){

        long double pi = pow( (long double)i/m,n) - pow( (long double)(i-1)/m, n);

        pi = 1.0 * i * pi;
        //cout << productiPi << " ";
        num += pi ;
    }

    //long double den = 1.0 * binaryExp(m ,n);


    cout <<  setprecision(6) << num << endl;

    return 0;
}