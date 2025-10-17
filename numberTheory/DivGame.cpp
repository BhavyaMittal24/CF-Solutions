#include<bits/stdc++.h>
using namespace std;

// p1 k1
// p1, p12, ... p1^x
// x(x+1)/2

int main(){

    long long n;
    cin >> n;
    if(n == 1) {
        cout << 0 << endl;
        return 0;
    }

    long long ans = 0;
    for(int i=2;i*i<=n;i++){
        if(n%i == 0){
            long long cnt =0;
            long long moves = 0;
            while(n%i == 0){
                n = n/i;
                cnt++;
            }
            // Binary search to find the maximum moves such that moves*(moves+1)/2 <= cnt
            long long left = 1;
            long long right = cnt;
            while(left <= right) {
                long long mid = left + (right - left) / 2;
                if(mid * (mid + 1) / 2 <= cnt) {
                    moves = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            ans += (moves-1);
        }
    }
    if(n > 1) ans += 1;
    cout << ans << endl;
    
    return 0;
}