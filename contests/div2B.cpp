#include<bits/stdc++.h>
using namespace std;

int mex(int l, int r, vector<int> &a){

    set<int> st;
    int k = r - l +1;
    for(int i = 0 ; i <= k-1; i++){
        st.insert(i);
    }

    for(int i = l ; i <=r ; i ++){
        if( st.count(a[i])) st.erase(a[i]);
    }

    if( st.size() ) return *st.begin();
    return k;
}

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n+1);
    bool isZeroPresent = false; 
    for(int i = 1; i <= n ; i ++){
        cin >> arr[i];
        if( arr[i] == 0) isZeroPresent = true;
    }

    if( !isZeroPresent) {
        cout << "NO\n";
        return;
    }

    // find the mex for 1,i and  mex for i+1, n

    sort(arr.begin(), arr.end());
    bool isPossible = true;
    for(int i = 1; i <= n-1 ; i ++){

        int mex1 = mex(1,1,arr);
        int mex2 = mex(i+1,n,arr);
        if( mex1 == mex2) {
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

    while(t--){
        solve();
    }
    return 0;
}
