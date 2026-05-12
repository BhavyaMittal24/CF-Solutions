#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, x, m;
    cin >> n >> x >> m;

    // x is the index where intially 1 is : 0 0 0 1 0 0 0 

    // merge dinterval
    int start = x;
    int end = x;

    for(int i = 0; i < m ; i ++){
        int s,e;
        cin >> s >> e;

        // interesection : max(s1,s2) <= min(e1, e2)
        if( max(start, s) <= min(end, e)){

            start = min(start, s);
            end = max(end, e);
        }
    }


    cout << end - start + 1 << "\n";
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