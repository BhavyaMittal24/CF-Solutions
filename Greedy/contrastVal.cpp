#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin >> n;

    vector<int> arr;

    for(int i = 0; i < n; i ++){

        int x;
        cin >> x;

        if(arr.size() == 0){
            arr.push_back(x);
            continue;
        }
        
        if(arr.back() == x) continue;
        arr.push_back(x);
    }

   // for(auto x: arr) cout << x << " ";
    // removed duplicates adjacent to each other
    // min length of array b having same contrast value

    if( arr.size() == 1){
        cout << "1\n";
        return;
    }
    int cnt = 2;

    // cnt peaks and downs

    // i = 1 to n-2
    for(int i = 1; i <= arr.size() - 2; i ++){

        //cout << arr[i] << " ";
        int prevDir = (arr[i] - arr[i-1]) > 0 ? +1 : -1;
        int nextDir = (arr[i+1] - arr[i]) > 0 ? +1 : -1;
        if( nextDir != prevDir){
            cnt++;
        }
    }

    cout << cnt << "\n";
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