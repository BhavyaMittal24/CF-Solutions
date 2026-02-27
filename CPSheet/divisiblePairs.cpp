#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n, x, y;
    cin >> n >> x >> y;

    // take in all the values for each ai

    map<int,vector<int>> mp;

    vector<int> arr(n);
    for(int i = 0; i < n; i ++){
        cin >> arr[i];

        // (arr[i] % y)
        mp[(arr[i] % y)].push_back(arr[i]);
    }

    // modulo y : [a1, a2, ..] for the same modulo y 

    long long cnt = 0;
    for(auto keys : mp){
        // get the values where same % y 
        vector<int> valuesWithSameModY = keys.second;

        // map storing the cnt of the ai % x as same 
        map<int,int> mp2;

        for(int val : valuesWithSameModY){
            val = (val % x);
            // ai %x
            mp2[val] ++;
        }

        // mp2 storign freq of ai%x
        for(auto it : mp2){
            int sameModXVal = it.first;
            int inverseVal = x - sameModXVal;

            if(inverseVal * 2 == x || sameModXVal == 0){
                long long cnt2 = mp2[sameModXVal];
                cnt += 1ll * (cnt2 * (cnt2-1) ) / 2;
            }

            else if(mp2.count(inverseVal) == 1 && (sameModXVal != inverseVal) )  {
                long long cnt1 = mp2[sameModXVal] * mp2[inverseVal];
                mp2[inverseVal] = 0;
                cnt += cnt1;
            }
        }
    }
    
    cout << cnt <<"\n";
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