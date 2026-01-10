#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n+1, 0);

    for(int i = 1; i <= n; i++) cin >> arr[i];


    if( n <= 1) {
        cout << 0 << endl;
        return;
    }

    int i = 1;
    int j = n;

    int leftSum = arr[i];
    int rightSum = arr[j];
    
    int maxCnt = 0;
    if(leftSum == rightSum) maxCnt = 2;

    while( i < j && i >=1 && j<= n ){
        if( leftSum == rightSum){
            i++;
            j--;

            leftSum += arr[i];
            rightSum += arr[j];
        }

        else if( leftSum < rightSum){
            i++;
            leftSum += arr[i];
        }
        else {
            j--;
            rightSum += arr[j];
        }
        if( leftSum == rightSum && i < j){
            maxCnt = max(maxCnt, i - 1 + 1 + n - j +1);
        }
    }

    cout << maxCnt  << endl;
    return ;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}