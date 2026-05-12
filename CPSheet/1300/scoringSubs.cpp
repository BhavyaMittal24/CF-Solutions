#include<bits/stdc++.h>
using namespace std;

int findLast(int idx, vector<int> &arr){
    int high = idx-1;
    int low = 0;

    int ans = -1;
    while(low <= high){
        int mid = (low + high) / 2;

        if(arr[mid] >= (idx - mid + 1)) {
            ans = mid;
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }

    return ans;
}
void solve(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n;  i++) cin >> arr[i];

    // for each k : from 0 to n-1 : find the first
    //               i-k  ..        i-2   i-1 |  i ,, find the last value of a[i-k] where a[i-k] >= k+1 because only then the score would be large 


    vector<int> ans;

    for(int k = 0; k < n; k ++){

        int farthestL = findLast(k,arr);

        if(farthestL == -1) {
            ans.push_back(1);
        }
        
        else {
            ans.push_back(k - farthestL + 1);
        }
    }

    for(auto it : ans){
        cout << it << " ";
    }
    cout << "\n";
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