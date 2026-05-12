#include<bits/stdc++.h>
using namespace std;


int main(){

    int n, r;
    cin >> n >> r;

    vector<int> d(n);

    for(int i = 0; i < n; i ++){
        cin >> d[i];
    }

    int left = 0;
    int right = 0;

    long long ans = 0;
    int distance = 0;
    while( right < n){
        
        // length of the shortest subarray with distance > r
        while(left <= right  &&  (d[right] - d[left] ) > r){
            ans += (n-right);
            left ++;
        }

        right++;
    }

    cout << ans << "\n";
    return 0;
}