#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n, h, l;
    cin >> n >> h >> l;
    vector<int> a(n);

    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    // find firt index lesser than equal to <= h and <= l
    int first = n;
    int second = n;

    for(int i = n-1; i >= 0; i--){
        if( first != n && second != n) break;
        if( a[i] <= h && first == n){
            first = i;
        }

        if( a[i] <= l && second == n){
            second = i;
        }
    }

    long long cnt = 0;

    if( first == n || second == n){
        cout << "0\n" ;
        return;
    }

    int i = 0;
    int j = max(first,second);
    
    int threshold = min(first, second);
    while(i <= threshold && (i < j) ){
        cnt++;
        i++;
        j--;
    }

    cout << cnt << "\n";
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
