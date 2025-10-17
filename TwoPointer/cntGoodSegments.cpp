#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    long long cnt = 0;
    int left = 0; 
    int right = 0;
    long long sum = 0;
    while(right <n){
        sum += a[right];
        while(sum > k){
            sum -= a[left];
            left++;
        }
        if(sum <=k) {
            cnt += (1ll*(right-left+1) * 1ll*(right-left+2))/2;
        }
        right++;
    }
    cout << cnt << endl;
    return 0;
}

// _ _ _ _ _ _ _ _ _ 
//     l       r
//  1 to 3
//[3] , [2,3] , [1,2,3]
// 1 + 2 + 3 = 6 
// 1 + 2 + 3 + r-1+1
// (r-l+1) (r-l+2)/2