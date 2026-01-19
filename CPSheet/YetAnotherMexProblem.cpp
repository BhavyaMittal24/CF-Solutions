#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;

    cin >> n >> k;

    set<int> s;
    // mex is min non negative value in an array of size k
    for(int i = 0; i <=n;i++){
        s.insert(i);
    }

    for(int i = 0 ; i < n; i ++){
        int x;
        cin >> x;
        if(s.count(x)) s.erase(x);
    }

    cout << min(*s.begin(), k-1) << endl;
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}