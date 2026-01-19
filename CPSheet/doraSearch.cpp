#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> arr(n+1);

    for(int i = 1; i <= n ; i++) cin >> arr[i];

    int minVal = 1;
    int maxVal = n;

    int left = 1;
    int right = n;

    pair<int,int> ans = {-1, -1};
    while( right - left + 1 >= 4){

        if( (arr[left] != minVal) && (arr[left] != maxVal) && (arr[right] != minVal) && (arr[right] != maxVal) ){
            ans = {left,right};
            break;
        }

        if( arr[left] == minVal){
            left++;
            minVal++;
        }

        else if( arr[left] == maxVal){
            left++;
            maxVal--;
        }

        if(arr[right] == minVal){
            right--;
            minVal++;
        }

        else if(arr[right] == maxVal){
            right--;
            maxVal--;
        }        
    }

    if(ans.first == -1) {
        cout << -1 << endl;
    }
    else {
        cout << ans.first << " " << ans.second << endl;
    }
    return;
}

int main(){

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}