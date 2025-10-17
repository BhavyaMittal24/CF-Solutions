#include<bits/stdc++.h>
using namespace std;

int main(){

    double a,b,c,d;
    cin >> a >> b >> c >> d;

    double ans = 1.0;
    ans = 1.0 * a*d;
    double e = ( 1.0* b * d) - (1.0 * a*c);
    ans = 1.0* ans / e;
    cout << fixed << setprecision(7) << ans << endl;
    return 0;
}