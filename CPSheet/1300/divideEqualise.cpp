#include<bits/stdc++.h>
using namespace std;

int N = 1e6;

// int : 4 bytes : 1 bute : 8 bits of memoery : 0 to 2^32 -1 : 0 to 31 are the bits where 0 is the LSB and MSB is 31 : 1byte has almost 2^32 memory 
// 256 MBmemoy limit : 2^8 * 2^10 * 2^ 10 bytes : 2^28 bytes of memory : ~ 2^2 * 1e7 bytes :  1e7 array : array og 1e7 N : 4*1e7 bytes of memoety : 1e9 bytes of memory
// max allowed array size is hence : 1e7 as 1e7 * 4 bytes each: 1e8 bytes : whcih is roughly 256 MB : 2^8 & 2^20 bytes  
vector<int> spf(N+1);
void solve(){

    int n;
    cin >> n;
    vector<int> arr(n);

    // for(int i = 0; i < n; i ++) cin >> arr[i];

    // can move any power from one index to another but the sum of power for a given prime must be distributed equally among all the n numbrs
    
    map<int,int> pf; // total count of powers of a, powers of b, ....

    // a1 = p1k1, p2k2, p3k3 // a2 = p1s1, p2s2, p3s3..  ... k1 + k2 must be divided equally 
    
    for(int i = 0; i < n; i ++){
        cin >> arr[i];

        //int x = spf[arr[i]];

        // find the pf and its cnt
        while(arr[i] > 1){

            int x = spf[arr[i]];

            int cnt = 0;
            while( arr[i] % x == 0){
                cnt++;
                arr[i] = arr[i] / x;
            }
            // mp[pf] += cnt;
            pf[x] += cnt;
        }
    }

    // go throgh all pf and the sum of powers for that pf across all n and chck if divisible
    
    bool isPossible = true;
    for(auto it : pf){

        int cnt = it.second;

        if(cnt % n){
            isPossible = false;
            break;
        }
    }

    if(isPossible) {
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

    for(int i = 1; i<= N; i ++){
        spf[i] = i;
    }

    // for ach numner : the smallest/ first prime factor is itself 
    // start probagating all the pf

    for(int i = 2; i*i <= N; i++){
        for( int j = i*i ; j <= N; j +=i){
            
            if(spf[j] == j){
                spf[j] = i;
            }
        }
    }

    while(t--){
        solve();
    }
    return 0;
}