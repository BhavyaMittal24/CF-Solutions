#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    cin >> n;
    string s;
    cin >> s;

    bool is2025 = false;
    bool is2026 = false;

    for(int i = 0; i < s.length(); i ++){
        if(s[i] == '2'){
            string substr;
            for(int  j = 0; (j < 4) && (i + j) < s.length() ; j ++){
                substr += s[i+j];
            }

            if( substr == "2026"){
                is2026 = true;
            }
            else if( substr == "2025"){
                is2025 = true;
            }
        }
    }
    
    if( is2026){
        cout << 0 << endl;
        return ;
    }

    else if( is2025){
        cout << 1 << endl;
        return ;
    }

    cout << 0 << endl;

    return ;
}

int main(){

    int t;
    cin >> t;

    while(t--){
        solve();
    }
    return 0;
}
