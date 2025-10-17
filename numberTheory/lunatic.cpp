#include<bits/stdc++.h>
using namespace std;


// n numbers
// array of n elements ai

// f(a,x) = (a1 % x)  (a2 % x)  ...  (an % x)
// find the lrgest x such that array is a palindrome

// a1%x = an%x  : max x
// a1-an %x = 0
// a2 - a(n-1) % x = 0
// a3 - a(n-2) % x = 0


// gcd(a,b)
// tc : o(log(min(a,b)));
long long gcd(long long a, long long b){
    while(b > 0){
        // when a >=b
        a = a%b;
        swap(a,b);
    }
    return a;
}

/// all this means that x should be a factor of all the differences. Now find the largest x
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    int i=0;
    int j=n-1;
    vector<int> diff;
    bool isPalindrome = true;
    while(i<j){
        if(a[i] != a[j]) isPalindrome = false;
        diff.push_back(abs(a[i]-a[j]));
        i++;
        j--;
    }

    if(isPalindrome) {
        cout << "0" << endl;
        return;
    }
    long long ans = 0;
    for(int i=0;i<diff.size();i++){
        ans = gcd(ans,diff[i]);
    }
    cout << ans << endl;
}

int main(){

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}