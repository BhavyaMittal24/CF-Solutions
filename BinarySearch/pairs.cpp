#include<bits/stdc++.h>
using namespace std;

bool f(long double x, vector<long double>& a, vector<long double>& b, int n, int k){
    vector<long double> transformedArray(n);
    for(int i=0;i<n;i++){
        transformedArray[i] = a[i] - x * b[i];
    }
    sort(transformedArray.begin(), transformedArray.end());
    long double sum = 0;
    // n-1 - x+1 = k
    for(int i=n-1;i>=n-k;i--){
        sum += transformedArray[i];
    }
    return sum >= 0;
}
int main(){

    int n,k;
    cin >> n >> k;
    vector<long double> a(n);
    vector<long double> b(n);
    for(int i=0;i<n;i++){
        cin >> a[i] >> b[i];
    }
  
    long double precision = 1e-7;
    // o(ss : 1e11 * 1e7) * (log(1e5) * 1e5)
    // log(1e18) * log(1e5)
    // 70 iterations * (1e5 * 20)
    // 1400 * 1e5
    long double low = 0;
    long double high = 1e10;
    long double ans = -1;
    long double mid = 0;
    
    for(int i=0;i<70;i++){
        mid = low + (high-low)/2;
        if(f(mid,a,b,n,k)){
            ans = mid;
            low = mid+precision;
        }
        else {
            high = mid-precision;
        }
    }
    
    cout << fixed << setprecision(6) << ans << endl;
    return 0;
}