#include<bits/stdc++.h>
using namespace std;

void solve(){

    long long a;
    int n;

    cin >> a >> n;
    // n = 2

    vector<int> d(n);

    for(int i = 0; i < n; i++) cin >> d[i];

    string number = to_string(a);

    // number of l + 1 digits" smallest numner

    // smaller digit
    int dig = d[0];

    long long minDiff = 1e18;

    int l = number.size();
    long long num1 = 0;

    for(int i = 0; i < l + 1; i++){
        if( (dig == 0) && (i == 0)) {
            num1 = num1*10 + d[1];
            dig = 0;
            continue;
        }

        num1 = num1 * 10 + dig;
    }

    minDiff = min(minDiff, abs( num1 - a));

    long long num2 = 0;
    dig = d[1];
    for(int i = 0; i < l - 1; i ++){
        num2 = 10* num2 + dig;
    }

    if(l >= 2){
        minDiff = min(minDiff, abs(num2 - a));
    }

    bool match = 1;

    long long curr = 0;

    for(int i = 0; i < l ; i++){

        int dig = number[i] - '0';
        for(auto x : d){

            if(x > dig){

                long long num = 0;
               
                num = curr*10 + x;
                for(int j = i+1; j < number.size(); j ++){
                    num = num*10 + d[0];
                }
                minDiff = min(minDiff, abs(a - num));
            }

            else if(x < dig){

                long long num = 0;
                
                num = curr* 10 + x;
                for(int j = i+1; j < number.size(); j ++){
                    num = num*10 + d[1];
                }
                minDiff = min(minDiff, abs(a - num));
            }
                     
        }

        // none of the digits d1 and d2 match with the digit[i ] : then we just retrun 
        if( (d[0] != dig) && (d[1] != dig) ){
            // both dont match
            match = 0;
            break;
        }

        curr = curr* 10 + (number[i] - '0');

    }

    if(match == 1){
        // all the digits match to d
        minDiff = 0;
    }

    cout << minDiff << "\n";
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