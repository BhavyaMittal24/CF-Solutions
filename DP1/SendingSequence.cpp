#include<bits/stdc++.h>
using namespace std;



void solve(){
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    vector<int> dp(n+1,0);

    // dp[i] : represents if i can make a array a from a` where a is of the form A( ) ()B C( ) and ( ) ( ) ( ) are segments of a`

    dp[n] = 1;

    int isTrue = 0;
    for(int i=n-1;i>=0;i--){
        int ahead = 0;
        int behind = 0;

        // a[i] is the size of segment
        if( (a[i]+i) <= n-1 ){
            // i can make a segment from ahead, usning a[i], but now also next subproblem should have the answer
            ahead = dp[i+1+a[i]];
        }
        
        int cntSegmentSizeSoFar = 1;
        // the semgnet ends at j
        for(int j=i+1;j<=n-1;j++){
            if(a[j] == cntSegmentSizeSoFar){
                behind = behind || dp[j+1];
            }
            cntSegmentSizeSoFar++;
        }

        // if i can make a segment successfully from behind or from ahead
        dp[i] = ahead || behind;
    }

    if(dp[0]){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;

    // for(int i=0; i<n; i++){
    //     cout << i << " " << dp[i] << " ";
    // }
    return;
}

// 5
// 3 7 2 1 1
int main(){

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}