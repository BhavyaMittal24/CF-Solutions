#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    cin >> n;
 
    set<int> st;
    for(int i = 0; i <=n;i++){
        st.insert(i);
    }

    vector<int> arr(n,0);
    for(int i = 0; i < n; i ++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    long long ans1 = 0;

    long long maxi =                                                                                                                                                                                                                                                                                     INT_MIN;
    for(int i = 0; i < n; i ++){

        if(st.count(arr[i]) == 1){
            st.erase(arr[i]);
        }

        maxi = max(maxi, 1ll*arr[i]);
        ans1 = ans1 + maxi + *st.begin();
    }

    for(int i = 0; i <=n;i++){
        st.insert(i);
    }

    int lastVal = arr.back();

    for(int i = n-1; i >= 1; i --){
        arr[i] = arr[i-1]; 
    }
    arr[0] = lastVal;

    long long ans = 1ll*n*lastVal;

    for(int i = 0; i < n; i ++){

        if(st.count(arr[i]) == 1){
            st.erase(arr[i]);
        }
        ans += 1ll*(*st.begin());
    }

    cout << max(ans,ans1) << "\n";
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