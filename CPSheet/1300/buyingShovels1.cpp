#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n, k;
    cin >> n >> k;
    // n is the number of exact shovels
    // k no of packages : ith package has i shovels. to buy n shovels, we need ot choose one pacakge type :and return the min count

    if( n <= k){

        // choose nth pacakge type : having n shovesl
        cout << "1\n";
        return;
    }

    // find the largest factor <= k of n
    // n > k 

    // n is the number 
    // i is the factor
    // n/i is another factor
    int maxFactor = 1;
    for(int i = 1; i * i <= n; i ++){

        if( n % i == 0){
            if(i <= k){
                maxFactor = max(maxFactor, i);
            }

            if( (n/i) <= k){
                maxFactor = max(maxFactor, n/i);
            }

        }
    }

    int x = n / maxFactor;
    cout << x << "\n";
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