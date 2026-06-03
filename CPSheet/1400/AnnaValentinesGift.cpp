#include<bits/stdc++.h>
using namespace std;

void solve(){

    // anna plays first
    int n, m;
    cin >> n >> m;

    // Anna : reduces trailing zeroes
    // Sasha : saves those trailing zeroes and combines with some other nuber a10000000a2

    int totalDigits = 0;

    vector<int> trailingZeroes;

    for(int i = 0; i < n; i ++){

        int x;
        cin >> x;

        if( (x % 10) ){
            // no trailing zero : 
            int dig = log10(x) + 1;
            totalDigits += dig;
        }
        else {
            // store the number of trailing 0s
            // anna reduces the maximum sasha saves the bext max
            int dig = 0;
            while((x % 10) == 0){
                dig++;
                x = x/10;
            }
            
            trailingZeroes.push_back(dig);
            dig = log10(x) + 1;
            totalDigits += dig;
        }
    }

    sort(trailingZeroes.begin(), trailingZeroes.end());

    // auto it = trailingZeroes.rbegin()+1;

    // while( it != trailingZeroes.rend()){
    //     totalDigits += *it;
    //     it = it+2;
    // }

    for(int i = trailingZeroes.size() - 2; i >= 0; i -=2){
        totalDigits += trailingZeroes[i];
    }

    if( totalDigits >= m+1){

        cout << "Sasha\n";
    }
    else {
        cout << "Anna\n";
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