#include<bits/stdc++.h>
using namespace std;

const int N = 1e3;

vector<int> spf(N+1);

void precompute(){

    for(int i = 1; i <= N; i++){
        spf[i] = i;
        // for the number i: it's smallest prime factor is i
    }

    for(int i = 2; i* i <= N ; i++){

        for(int j = i * i; j <= N; j = j + i){

            // j = j + i // 2,4, 6 ... 3, 9, 12, 15
            // value of spf[j] is not set default value : j
            if(spf[j] == j){
                spf[j] = i;
            }
        }
    }

}

int exp(int base, int exponent){

    int ans = 1;

    while(exponent > 0){

        if(exponent & 1){
            ans = ans * base;
        }

        base = base * base;
        exponent = exponent >> 1;
    }
    return ans;
}
void solve(){

    int n;
    cin >> n;

    vector<pair<int,int> > pf;

    // while(n > 1){
    //     int prime = spf[n];

    //     // 42 : 2*3*7
    //     int cnt = 0;
    //     while( n % prime == 0){
    //         n = n/prime;
    //         cnt++;
    //     }
    //     cout << prime << " " << cnt << '\n';
    //     pf.push_back({prime,cnt});
    // }

    int x = n;
    for(int i = 2; i * i <=x ; i++ ){

        int cnt = 0;

        if( n % i == 0){
            while( n % i == 0){
                n = n /i;
                cnt++;
            }

           // cout << i << " " << cnt << '\n';
            pf.push_back({i,cnt});
        }
    }

    if( n > 1){
        pf.push_back({n,1});
    }
    // now make logic : 

    if(pf.size() >= 3){
        cout << "YES\n";
        int val1 = pf[0].first;
        int val2 = pf[1].first;
        int val3 = x / (val1* val2);
        cout << val1 << " " << val2 << " " << val3 << "\n";
    }

    else if( pf.size() == 2){
        if(pf[0].second + pf[1].second <= 3) {
            cout << "NO\n";
            return;
        }

        int val1 = pf[0].first;

        int val2 =  exp(pf[0].first, pf[0].second - 1);
        int val3 = exp(pf[1].first, pf[1].second);

        if( pf[1].second >= 2){
            val2 *= pf[1].first;
            val3 = exp(pf[1].first, pf[1].second - 1);
        }
        cout << "YES\n";
        cout << val1 << " " << val2 << " " << val3 << "\n";
    }

    else if(pf.size() == 1){
        if(pf[0].second < 6){
            cout << "NO\n";
            return;
        }
        // power count should be greater than 6

        int val1 = pf[0].first;
        int val2 = val1* val1;
        int val3 = exp(pf[0].first, pf[0].second-3);
        cout << "YES\n";
        cout << val1 << " " << val2 << " " << val3 << "\n";
    }
    return;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    //precompute();

    while(t--){
        solve();
    }

    return 0;
}