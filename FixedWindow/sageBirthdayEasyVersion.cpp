#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i ++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    if(n < 3){
        cout << "0\n";
        for(auto a : arr){
            cout << a << " ";
        }
        cout << "\n";
        return 0;
    }


    vector<int> ans(n,0);

    int cnt = 0;
    if(n%2 == 0){
        cnt = n/2 - 1;
    }
    else {
        cnt = n/2;
    }
    int i = 0;
    int j = cnt;
    int idx = 1;

    while( i < cnt && j < n){
        ans[idx] = arr[i];

        if(idx == 1){
            ans[idx-1] = arr[j];
            j++;
            ans[idx+1] = arr[j];
            j++;
            idx+=2;
            i++;
        }
        else {
            ans[idx] = arr[i];
            ans[idx+1] = arr[j];
            j++;
            idx = idx+2;
            i++;
        }
    }

    if(n % 2 == 0) {
        ans.back() = arr[j]; 
    }
    cout << cnt << "\n";
    for(auto it : ans){
        cout << it << " " ;
    }
    cout << "\n";
    return 0;
}