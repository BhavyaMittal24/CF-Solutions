#include<bits/stdc++.h>
using namespace std;

bool compare(pair<long long, long long>& a, pair<long long, long long> &b)
{
    return (a.second-a.first) > (b.second - b.first);
}

void solve(){

    int n;
    cin >> n;
 
    vector<long long> a(n);
    vector<long long> b(n);

    long long sum = 0;

    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }

    for(int i = 0; i < n; i ++){

        cin >> b[i];
    }


    vector<long long> maxSum(n,0);

    for(int i = 0; i < n; i ++){
        maxSum[i] = max(a[i], b[i]);
        if( i>= 1) maxSum[i] += maxSum[i-1];
    }

    long long maxSumVal = 0;
    // assuming this is the max value index for a

    for(int i = 0; i < n; i ++){

        long long sum = maxSum[n-1] - maxSum[i];
        if(i >= 1) sum += maxSum[i-1];

        // since there is on ly max value
        maxSumVal = max(maxSumVal, sum + a[i] + b[i]);
    }

    cout << maxSumVal << '\n';
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