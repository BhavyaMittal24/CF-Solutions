#include<bits/stdc++.h>
using namespace std;

void solve() {

    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> numsToRemove(n+1,0);
    vector<int> vis(n+1, 0);

    for(int i = 1; i <=n ; i ++){
        if(s[i-1] == '0'){
            // 2 4 8 9 11
            numsToRemove[i] = 1;
        }
    }

    long long ans = 0;
    for(int i = 1; i <= n && !numsToRemove.empty(); i ++){

        long long cnt = 0;
        for(int j = i; j <= n && !numsToRemove.empty(); j=j+i){

            if(numsToRemove[j] == 1 && vis[j] == 0){
                vis[j] = 1;
                cnt++;
                numsToRemove[j] = 0;
            }
            else if( numsToRemove[j] == 0 && vis[j] == 0) break;
        }

        ans += (i*cnt);
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