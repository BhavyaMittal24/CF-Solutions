#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){

    if(b == 0){
        return a;
    }

    return gcd(b, a % b);
}

void solve(){

    int n;
    cin >> n;
    vector<int> arr(n); // ai <= 1e9  <= 2^30 : msb is 30 : 31 bits : 0 to 30

    map<int,int> mp; // mp storign the bit position : how many numbers have that bit positin as set : ie all those can be grouped and reduced in one operation
    // bit pos 2 : cnt = 3 : so 3 numbers have that bit pos 2 as set: so if i take them together : a1 a2 a3, x will have bit pos 2 set : and remove tht bit pos

    for(int i = 0; i < n; i ++){
        cin >> arr[i];

        int msb = log2(arr[i]);

        for(int j = 0; j <= msb ; j ++){

            if( (arr[i] & (1 << j)) != 0){
                // jth bit is set
                mp[j] ++;
            }
        }
    }
    // 3 -> 4
    // 2 -> 5
    // 1 -> 2
    // 0 -> 3
    // if 3 is selected as k, i can remove 0th bit successfully, then 1st bit can never be set 0 for all numbers : 

    int gcdBitPosCount = 0;

    for(auto it : mp){
        gcdBitPosCount = gcd(gcdBitPosCount, it.second);
    }

    // print all the factors for this numner :
    for(int i = 1; i <= gcdBitPosCount ; i ++){
        if(gcdBitPosCount % i == 0){
            cout << i << " ";
        }
    }

    if(gcdBitPosCount == 0){
        for(int i = 1; i <= n; i ++){
            cout << i << " ";
        }    
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