#include<bits/stdc++.h>
using namespace std;

long long cntEmoji(long long mid, long long k){

    long long cnt = 0;

    if( mid <= k) {
        cnt = 1ll* mid * (mid+1) / 2;
    }

    else {

        int extra = mid - k;

        cnt = 1ll* k * (k+1) / 2;

        cnt += (extra * k);
        cnt -=  1ll* extra * (extra + 1) / 2;
    }
    return cnt;

}

void solve(){

    long long k;
    long long x;
    cin >> k >> x;

    // x emotes in succession are allowed before a ban

    // wants tp print emojis in a triangle with 2k-1 total messages and k^2 emojis
    // printing 
    // 1
    // 2
    // 3
    // k-1
    // k : k emojis in the kth message 
    // k-1 .. and so on emojis 

    // 4 6

    // k = 4, x = 6 : total emojis allowed = 6
    // find the total number if messages sent 
    // total messages for the triange : 16
    // 1 + 2 + 3 : 3 rows

    // max value of the totalk messages is 2k -1 and not get banned at all

    // binary sear chfor the maximum no of messages befreg etting banned

    // messages can be from 0 to 2*k -1 such that emojs <= x

    if(1ll*k*k <= x){
        // total emojis <= x : and 
        cout << 2*k - 1 << "\n";
        return;
    }

    long long low = 1;
    long long high = 2ll*k - 1;

    long long ans = -1;

    while( low <= high){
        long long mid = 1ll*low + 1ll*(high - low)/2;

        // mid no of messqges : 
        
        if( cntEmoji(mid, k) >= x){
            ans = mid;
            high = mid - 1;
            // min value of the row where no of emojis >= x
        }

        else {
            low = mid+1;
        }
    }

    cout << ans << "\n";
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