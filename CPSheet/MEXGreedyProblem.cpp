#include<bits/stdc++.h>
using namespace std;


void solve(){

    int n;
    cin >> n;
    vector<int> arr(n);

    // ai <= 1e9
    // it is optimal to place nubers like this : MAX 0 1 2 3 .. mex-1 , any order ::
    // Max value of maxi + mexi for each prefix from 0 to i.

    // aim is t have the max value at the very start and the mex also right from i =  mex - 1  to i = n-1
    // if i place numbers like : 10 9 8 7 ... then mex will always be 0 here : place in increasing order

    map<int,int> mp;
    int maxi = -1;
    for(int i = 0; i <n; i ++){
        cin >> arr[i];
        mp[arr[i]]++;
        maxi = max(maxi, arr[i]);
    }

    vector<int> result;
    result.push_back(maxi);
    mp[maxi]--;

    if(mp[maxi] == 0) mp.erase(maxi);

    for(auto &it : mp){

        if(it.first == maxi) continue;
        if(it.second > 0){
            result.push_back(it.first);
            mp[it.first]--;
            //if(mp[it.first]==0) mp.erase(it.first);
        }
    }

    // arranged values like max 1 2 3 4...
    
    for(auto it : mp){
        int freq = it.second;
        while(freq > 0){
            result.push_back(it.first);
            mp[it.first]--;
            freq = mp[it.first];
        }
    }

    // now with this array find the max value
    long long ans = 0;

    maxi = -1;
    int mexi = 0;
    map<int,int> calc;

    for(int x : result){

        maxi = max(maxi, x);

        // store all in rthis number
        calc[x]++;

        // 0 0 1 1
        // 2 2 3 3 1 0 
        while(calc[mexi] > 0){
            mexi++;
        }

        ans = ans + 1ll*maxi + 1ll*mexi;
    }

    cout << ans << "\n";
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