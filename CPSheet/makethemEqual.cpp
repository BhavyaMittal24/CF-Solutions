#include<bits/stdc++.h>
using namespace std;


void solve(){

    int n;
    char ch;
    cin >> n >> ch;
    string s;

    cin >> s;
    // max answer has to be 2 : put x as n and 1 to n-1 are set to character c and for the nth character, if it's not c, then find a x like n-1 whihc does not divide n

    for(int i =1; i <= n; i ++){
        // check if for a given i, all it's multiples are equal to character ch : use 1 operation to make all others ch and i-1 to make all 
        bool multiplesSame = true;
        for(int j = i; j<=n; j +=i){
            if(s[j-1] != ch) {
                multiplesSame = false;
                break;
            }
        }
        // all multiples are same of x = 1
        if(multiplesSame && i == 1){
            cout << 0 << "\n";
            return;
        }
        else if(multiplesSame){
            cout <<"1\n";
            cout << i << "\n"; 
            return;
        }
    }

    cout << "2\n";
    cout << n << " " << n-1 << "\n";
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