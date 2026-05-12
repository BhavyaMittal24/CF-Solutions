#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    vector<pair<long long,int>> arr(n);

    for(int i = 0; i < n; i ++){
        int x;
        cin >> x;
        arr[i] = {x,i+1};
        // x, index
    }

    sort(arr.begin(), arr.end());
    // found thr sorted key value pairs according to the min value and their respective indices

    vector<int> ans;

    vector<long long> prefix(n,0);

    if( n <= 2) {
        cout << "0\n";
        return 0;
    }

    for(int i = 0; i < n; i ++){
        if( i == 0){
            prefix[i] = arr[i].first;
            continue;
        }

        prefix[i] = prefix[i-1] + 1ll*arr[i].first;
    }

    // found the sum of all values from 0 to i

    // 0 ,1 ,2 : n-1, n-2, n-3
    if( arr[n-2].first  == prefix[n-3]){
        ans.push_back(arr[n-1].second);
    }

    for(int i = 0; i <= n-2; i ++){
        // remove from 1st to 2nd last index

        if(arr[n-1].first == (prefix[n-2] - arr[i].first)){

            ans.push_back(arr[i].second);
        }
    }


    // [8,3,5,2]
    
    // j = 1, [3,5,2]

    // j = 4 [8,3,5]
    
    cout << ans.size() << "\n";

    for(auto it : ans){
        cout << it << " ";
    }
    cout << "\n";
    return 0;
}

// [1,3,3,7] : 7 = 1 + 3 +3
 
// remove one element so that ..      sun of all elements is equal to one big element 