#include<bits/stdc++.h>
using namespace std;

int main(){

    int n, m;
    cin >> n >> m;

    map<string, vector<int>> mp;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int x ;
            cin >> x;
            string vert = to_string(x) + "y";
            string hor = to_string(x) + "x";
            mp[vert].push_back(i);
            mp[hor].push_back(j); // 
        }
    }

    long long ans = 0;

    for(auto & it : mp){
        vector<int> & indices = it.second;
        int k = indices.size();
        sort(indices.begin(), indices.end());
        for(int i = k-1; i >= 0; i--){
            //cout << indices[i] << ' ';
            ans +=  (2ll*i - 1ll*k+ 1) * (indices[i]) ; 
        }
        cout << "\n";
    }
    cout << ans << '\n';
    return 0;
}