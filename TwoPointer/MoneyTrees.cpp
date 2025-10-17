// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int n,k;
//         cin >> n >> k;
//         vector<int> h(n);
//         vector<int> f(n);
//         for(int i=0;i<n;i++) cin >> f[i];
//         for(int i=0;i<n;i++) cin >> h[i];
//         int maxLen = 0;

//         int right = 0;
//         int left = 0;

//         // a good subarray is when the sum of fruits <=k and the hi % hi+1 = 0 and so on in the entire window of dynamic size
//         long long sum = 0;
//         int top = h[0];
//         while(right < n){
//             sum += f[right];
//             while(left <=right && (sum > k || top % h[right] != 0)){
//                 sum -= f[left];
//                 left++;
//                 if(left == right){
//                     top = h[right];
//                 }
//             }
//             if(sum <=k && top % h[right] == 0){
//                 maxLen = max(maxLen,right-left+1);
//             }
//             top = h[right];
//             right++;
//         }
//         cout << maxLen << endl;     
//     }
//     return 0;
// }

// // 5 12
// // 3 2 4 1 8
// // 4 4 2 4 1

// // 4 8  k = 8

// // fruits
// // 5 4 1 2

// // height
// // 6 2 3 1

// // left 0  2
// // right 0 1
// // sum = 5 0
// // top = 6 6

// // maxl= 1 

#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<long long> f(n);
    vector<int> h(n);
    for(int i = 0; i < n; ++i) cin >> f[i];
    for(int i = 0; i < n; ++i) cin >> h[i];

    int maxLen = 0;
    long long current_sum = 0;
    int left = 0;
    int right = 0;

    while(right < n){
        // whenever in any case the condition breaks, my lsiding window shifts aeada nd starts from right.
        if(right > 0 && h[right-1] % h[right] != 0){
            left = right;
            current_sum = 0;
        }
        current_sum += f[right];
        while( current_sum > k){
            current_sum -=f[left];
            left++;
        }
        if( current_sum <=k){
            maxLen = max(maxLen,right-left+1);
        }
    right++;
    }
    cout << maxLen << endl;
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