#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    
    bool isPossible = false;
    for(int i = 0; i < n ; i++){
        int x;
        cin >> x;
        if( x == 67) {
            isPossible = true;
            // Removed the break to ensure we read all 'n' integers
        }
    }

    if(isPossible) cout << "YES\n"; 
    else cout << "NO\n";
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