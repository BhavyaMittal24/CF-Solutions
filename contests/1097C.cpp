#include<bits/stdc++.h>
using namespace std;


void solve(){

    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    int sum1 = 0;
    int sum2 = 0;

    bool isPossible = true;
    for(int i = 0; i < n; i ++){

        int val1 = ( a[i] == '(' ) ? +1 : -1;
        int val2 = ( b[i] == '(' ) ? +1 : -1;

        if(a[i] == b[i]){
            sum1 += val1;
            sum2 += val2;
        }

        else {
            // 4, 3 : 
            if(sum1 > sum2){
                sum1 += -1;
                sum2 += 1;
            }
            else {
                sum1 += 1;
                sum2 += -1;
            }
        }

        if(sum1 < 0 || sum2 < 0){
            isPossible = false;
            break;
        }
    }


    if( sum1 != 0 || sum2 != 0) isPossible = false;

    if(isPossible){
        cout << "YES\n";
    }

    else {
        cout << "NO\n";
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