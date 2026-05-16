#include<bits/stdc++.h>
using namespace std;

void form(int i, long long curr,  int d, vector<long long> & numbers, int d1, int d2){

    if( i == d+1){
        curr = curr/10;
        numbers.push_back(curr);
        curr = curr/10;
        numbers.push_back(curr);
        curr = curr/10;
        numbers.push_back(curr);
        return;
    }

    curr += 1ll*d1;

    form(i+1, 1ll*curr*10, d, numbers, d1, d2);
    curr -= 1ll*d1;

    curr += 1ll*d2;
    form(i+1, 1ll*curr*10, d, numbers, d1, d2);
}

void solve(){

    long long a;
    int n;
    cin >> a >> n;

    int d1;
    int d2;
    cin >> d1 >> d2;
    // form numbers from d1 and d2 closest to a : 


    int d = log10(a+1) + 1;

    
    vector<long long> numbers;

    form(0,0,d, numbers, d1, d2);

    long long minDiff = 1e18;

    for(long long num : numbers ){

        //cout << num << " \n";
        minDiff = min(minDiff, abs(num - a));
    }

    cout << minDiff << "\n";


    return;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >>t;

    while(t--){
        solve();
    }
    return 0;
}