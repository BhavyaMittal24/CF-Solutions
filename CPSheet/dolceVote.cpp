#include<bits/stdc++.h>
using namespace std;


void solve(){

    int n, x;
    cin >> n >> x;

    vector<int> arr(n+1, 0);
    vector<long long> preSum(n+1,0);


    for(int i = 1; i <=n ; i ++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    for(int i = 1; i <= n ; i ++){
        preSum[i] = preSum[i-1] + arr[i];
    }

    // for each pack pick the cnt of days where we can buy all the packs from 1 to i : ie prefix sum of i + no of days*i <=x : cnt total days
    long long cnt = 0;

    for(int pack = n; pack >= 1; pack --){

        // no of days for which we can buy all the "pack" packs of sugar
        long long days = 1ll* (x - preSum[pack] + pack);
        //cout << days << "\n";
        days = days/pack;
        if(days <= 0) days = 0;
        cnt += days;
    }

    cout << cnt << "\n";
    return;
}
int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}