#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b){
    if( b == 0) return a;
    
    return gcd( b , a % b);
}
void solve(){

    int n;
    cin >> n;

    long long gcdOdd = 0;
    long long gcdEven = 0;
    vector<long long> even;
    vector<long long> odd;

    bool isOnePresentInOdd = false;
    bool isOnePresentInEven = false;
    for(int i = 1; i <= n ; i ++){
        long long x;
        cin >> x;
        if( i % 2){
            odd.push_back(x);
            if( x == 1) isOnePresentInOdd = true;
            gcdOdd = gcd(gcdOdd, x);
        }
        else {
            even.push_back(x);
            if(x == 1) isOnePresentInEven = true;
            gcdEven = gcd(gcdEven, x);
        }
    }

    // if any where 1 is present, then gcd of all the odd values becomes 1
    // if any one value in the odd is 1 : then gcd of all odd becomes 1
    // similarly if anywhere 1 value in even is even, then gcd of all becomes 1
   

    // gcd(x , 1) = 1
    

    // d should be among the ai

    bool isDivisibleByOddGCD = false;

    for(long long num : even){
        if( num % gcdOdd == 0) isDivisibleByOddGCD = true; 
    }

    
    bool isDivisibleByEvenGCD = false;
    for(long long num : odd){
        if( num % gcdEven == 0) isDivisibleByEvenGCD = true;
    }

    if( !isDivisibleByOddGCD) {
        cout << gcdOdd << endl;
        return;
    }

    if( !isDivisibleByEvenGCD){
        cout << gcdEven << endl;
        return;
    }

    cout << 0 << endl;
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