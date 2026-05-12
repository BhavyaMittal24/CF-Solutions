#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    cin >> n;

    vector<int> a(n);
    // vector<int> b(n);

    for(int i = 0; i < n; i ++) cin >> a[i];
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        a[i] = a[i] - x;
    }

    vector<int> maxIndices;

    int maxValue = INT_MIN;
    for(int i = 0; i < n; i ++){

        if(maxValue < a[i]){
            maxIndices = {i+1};
            maxValue = a[i];
        }
        else if(maxValue == a[i]) {
            maxIndices.push_back(i+1);
        }
    }

    cout << maxIndices.size() << "\n";
    for(auto x : maxIndices){
        cout << x << " ";
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