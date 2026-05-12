#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> p(n);

    for(int i = 0; i < n;i ++) cin >> p[i];

    // permutation 
    vector<int> maxValue;

    maxValue.push_back(p[0]);

    long long ans = 0;
    for(int i = 1; i <= n-2; i ++){

        int prevSign =  ( (p[i] - p[i-1]) > 0 )  ? +1 : -1;
        int nextSign =  ( ( p[i+1] - p[i] ) > 0 ) ? +1 : -1; 
        if(prevSign != nextSign){
            // we fpubd a peak or valley
            ans += abs(maxValue.back() - p[i]);

            maxValue.push_back(p[i]);
        }
    }

    // i = n-1
    ans += abs(maxValue.back() - p[n-1]);

    maxValue.push_back(p[n-1]);
    cout << maxValue.size() << "\n";
    for(auto x : maxValue) {
        cout << x << " ";
    }
    cout << "\n";
    return;
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