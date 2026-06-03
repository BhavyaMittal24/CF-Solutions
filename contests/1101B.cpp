#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    cin >> n;
    
    vector<long long> height(n);
    for(int i = 0; i < n; i ++){
        cin >> height[i];
    }

    vector<long long> ans(n,0);

    ans[0] = height[0];

    long long extra = 0;
    for(int i = 1; i < n; i++){
        if( height[i] >= ans[i-1]){
            extra += height[i] - ans[i-1];
            ans[i] = ans[i-1];
        }

        else {
            // heighti < maxHeight;
            
            // find the new max height for the entire prefix
            int low = 1;
            int high = ans[i-1]; // max height from 1 to prevMax

            int maxHeight = -1;
            while(low <= high){
                int mid = (low + high)/2;

                // possible height

                long long currArea = 1ll*(i+1)*mid;
                long long prevArea = 1ll*i*ans[i-1] + extra + height[i];

                if(currArea <= prevArea){
                    maxHeight = mid;
                    low = mid + 1;
                }
                else {
                    high = mid-1;
                }
            }

            long long prevArea = 1ll*i*ans[i-1] + extra + height[i];

            extra =  prevArea - 1ll*(i+1) * maxHeight;
            ans[i] = maxHeight;
        }

    }
    
    for(auto it : ans){
        cout << it << " ";
    }

    cout << "\n";

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