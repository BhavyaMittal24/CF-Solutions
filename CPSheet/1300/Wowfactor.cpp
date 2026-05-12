#include<bits/stdc++.h>
using namespace std;

int main(){

    string s;

    cin >> s;

    int n = s.length();
    vector<int> cntLeft(n,0);

    vector<int> cntRight(n,0);

    for(int i = 0;  i < s.length() ; i++){
        if( i == 0) continue;

        if( s[i] == 'v' && s[i-1] == 'v'){
            cntLeft[i] = cntLeft[i-1] + 1;
        }
        else cntLeft[i] = cntLeft[i-1];
    }

    
    for(int i = n-1;  i >= 0 ; i--){
        if( i == n-1) continue;

        if( s[i] == 'v' && s[i+1] == 'v'){
            cntRight[i] = cntRight[i+1] + 1;
        }
        else cntRight[i] = cntRight[i+1];
    }

    // find the total ans

    long long ans = 0;

    for(int i = 0; i < n; i ++){

        //cout << cntLeft[i] << " " << cntRight[i] << "\n";
        if( s[i] == 'o'){
            ans = ans + 1ll* cntRight[i] * cntLeft[i];
        }
    }

    cout << ans << "\n";
    return 0;
}

/*

vvvovvv
0122234
4322210
*/