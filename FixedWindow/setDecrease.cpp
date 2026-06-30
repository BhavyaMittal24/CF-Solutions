#include<bits/stdc++.h>
using namespace std;

bool check(long long mid, long long k, vector<long long> & arr, vector<long long> & prefix){

    // max mid operations are performed

    int j = 0; // type 2 operations

    long long n = 1ll*arr.size();
    // mid - j can be done on a0
    // j=n-1              j=0                        
    // 0 1 ...............n-1
    bool isPossible = false;

    for(int j = 0; j <= min(n-1,mid) ; j++){

        long long arrSum = 0;

        // mid - j type 1 operations performed
        long long val1 =  arr[0] - (mid - j);

        arrSum = 1ll*(j+1) * val1;
        int idx = n - j-1;
        arrSum += prefix[idx] - prefix[0];
        if(arrSum <= k){
            isPossible = true;
            break;
        }
    }

    return isPossible;
}
void solve(){

    long long n;
    long long k;
    cin >> n >> k;

    vector<long long> arr(n,0);
    
    vector<long long> prefix(n,0);

    for(int i = 0; i < n; i ++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    prefix[0] = arr[0];
    for(int i = 1; i < n; i ++){
        prefix[i] = prefix[i-1] + arr[i];
    }
    long long ans = -1;
    long long low = 0;
    long long high = 2*1e9; // go from 1e9 to 0 and make it across all n-1

    while( low <= high){

        long long mid = (low + high)/2;

        if(check(mid, k, arr, prefix)){
            ans = mid;
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }

    cout << ans << '\n';
}

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}