#include<bits/stdc++.h>
using namespace std;

int findMaximumIndexLessThanVal(int aj, vector<int>& indexes, int idx){

    int high = idx-1;
    int low = 0;

    int ans = -1;
    while(low <= high){

        int mid = (low + high)/2;

        if(indexes[mid] >= aj){
            high = mid -1;
        }
        else {
            // i < aj
            ans = mid;
            low = mid+1;
        }
     }
    
     return ans + 1;
}

void solve(){

    int n;
    cin >> n;
    //  ai < i 
    // aj < j
    // ai < i < aj < j
    // sort based on the indexes

    // for a given aj, find the maximum i such that i < aj
    vector<int> indexes;
    vector<int> values;

    for(int i = 1; i <= n; i ++){
        int x;
        cin >> x;
        if( i > x){
            // ie ai < i
            indexes.push_back(i);
            values.push_back(x);
            // { i, x } pair is present
        }
    }

    long long cnt = 0;
    for(int i = values.size() -1; i >= 0; i --){

        // find the maximum i such that  aj, j
        // aj > i
        // i1 , i2 ... ik  aj     im
        cnt += findMaximumIndexLessThanVal(values[i], indexes, i);
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