#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin >> n;

    string s;
    // cnt thw number of consecutibe 10s
    cin >> s;
    
    int cnt = 0;
    int si = -1;
    int ei = -1;

    for(int i = 0; i < n ; i ++){
        if( i == 0) continue;
        if( s[i] == '0' && s[i-1] == '1' ){

            if(cnt == 0) {
                int j = i-1;
                while( j >= 0 && s[j] == '1'){
                    j--;
                }
                si = j+1;
                int k = i;
                while( k < n && s[k ] == '0'){
                    k++;
                }
                ei = k - 1;
            }
            cnt ++;
        }
    }

    if(cnt % 2 == 0) {
        cout << "Bob\n";
    }
    else {
        cout << "Alice\n";
        cout <<  ei - si + 1 << "\n";
        cout << si+1 << " " << ei+1 << "\n";
    }

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
