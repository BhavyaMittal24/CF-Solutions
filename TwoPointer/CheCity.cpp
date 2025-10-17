// in n elements, find the no of subarrays wuch that the total length > r : (only then boys will not each other)
// find the count 

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, r;
    cin >> n >> r;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    long long cnt = 0;

    int right = 0;
    int left = 0;

    while(right < n){
        while(left <=right && a[right] - a[left] > r){
            cnt = cnt + (n-right);
            left++;
        }
        right++;
    }
    cout << cnt << endl;
    return 0;
}