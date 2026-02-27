#include<bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;

    vector<int> arr(n+1);

    long long sum = 0;
    map<int,int> mp;

    for(int i = 1; i <= n; i ++){

        cin >> arr[i];
        mp[i] = arr[i];
        sum += arr[i];
    }

    int commonVal = -1;
    
    for(int i = 0; i < q; i ++){
        int type, idx, val;
        cin >> type;
        if(type == 2){
            cin >> val;
            commonVal = val;
            sum = 1ll*n * val;
            map<int,int> mp1;
            mp = mp1;
            cout << sum << "\n";
        }

        else {
            // type = 1
            cin >> idx >> val;
            // this idx is updated in the map ie value is set already other than common value
            if(mp.find(idx) != mp.end()){
                sum -= mp[idx];
            }

            // idx is not found in map, ie value for idx is srtill commonvalue
            else {
                sum -= commonVal;
            }
            sum += val;
            // adding to the map
            mp[idx] = val;
            cout << sum << "\n";
        }
    }

    return 0;
}