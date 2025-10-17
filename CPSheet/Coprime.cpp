#include<bits/stdc++.h>
using namespace std;

// isPrime[i] : prime or not, lastindex in the array

//vector<int> primes(1001,1);

int gcd(int a, int b){
    while(b>0){
        a = a % b;
        swap(a,b);
    }
    return a;
}
void solve(){
    int n;
    cin >> n;
    vector<int> lastSeen(1001,-1);
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
        lastSeen[a[i]] = i+1;
    }

    int maxSum = -1;
    for(int i=1;i<=1000;i++){
       for(int j=1;j<=1000;j++){
            if(lastSeen[i] != -1 && lastSeen[j] != -1 && gcd(i,j) == 1){
                maxSum = max(maxSum, lastSeen[i]+lastSeen[j]);
            }
       }
    }
     cout << maxSum<< endl;
}
///
// 1000 log(log(1000))
// void sieve(){
//     for(int i=2;i<=1000;i++){
//         if(primes[i] == 1){
//             for(int j=i*i;j<=1000;j+=i){
//                 primes[j] = 0;
//             }
//         }
//     }
// }

int main(){
    int t;
    cin >> t;
    //sieve();
    // cout << gcd(34,35) << endl;
    while(t--){
        solve();
    }
    return 0;
}