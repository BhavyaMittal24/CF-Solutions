#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    cin >> n;
    vector<long long> arr(n);

    for(int i = 0; i < n; i ++) cin >> arr[i];

    long long oddSum  = 0;
    long long evenSum = 0;

    bool isPossible = false;
    set<long long> diff;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            evenSum += arr[i];
        }
        // odd parity index
        else {
            oddSum += arr[i];
        }

        long long val = oddSum - evenSum;
        
        if( diff.find(val) != diff.end() || val == 0){
            isPossible = true;
            break;
        }
        
        diff.insert(val);
    }

    if(isPossible){
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }

    return;
}

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while(t--){
        solve();
    }
    return 0;
}