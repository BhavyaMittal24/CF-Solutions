#include<bits/stdc++.h>
using namespace std;

int main(){

    int n, a, b;
    cin >> n >> a >> b;
    vector<long long> arr(n+1, 0);
    vector<long long> prefix(n+1, 0);
    
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        prefix[i] = prefix[i-1] + arr[i];
    }

    // length is between a and b
    //    [r-b          r-a]              r
    // l,r :   pre[r] - pre[l-1]

    set<pair<long long, int>> st;

    long long maxi = -1e18;
    for(int r = 0; r <= n; r++){
        
        if( r >= b + 1){
            if(!st.empty()) st.erase({prefix[r-b-1], r-b-1});
        }

        if( r >= a){
            st.insert({prefix[r-a], r-a});
            // r >= a, insert 0
            // min len : a from 1 to index a
            long long sum = prefix[r] - st.begin()->first;
            maxi = max(maxi, sum);
        }

    }

    cout << maxi << '\n';
    return 0;
}
