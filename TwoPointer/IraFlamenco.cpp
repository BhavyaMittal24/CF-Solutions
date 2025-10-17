#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9 + 7;

// Function to compute (base^exp) % mod using binary exponentiation
long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

// Function to compute modular multiplicative inverse of n
long long modInverse(long long n) {
    return power(n, MOD - 2);
}

// Function for modular division: (a / b) % mod
long long mod_div(long long a, long long b) {
    a = a % MOD;
    long long inv = modInverse(b);
    return (inv * a) % MOD;
}

// void solve() {
//     int n, m;
//     cin >> n >> m;
//     vector<int> arr(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> arr[i];
//     }
    
//     map<int, int> mp;
//     for(auto i: arr) {
//         mp[i]++;
//     }

//     auto it = mp.begin();
//     long long mul = 1;
//     int count = 0;
//     long long ans = 0;
    
//     for(auto const& i: mp) {
//         count++;
//         mul = (mul * 1LL * (i.second)) % MOD;
        
//         if(count > m) {
//             mul = mod_div(mul, it->second);
//             it++;
//         }
        
//         if(count >= m) {
//             if((i.first - it->first < m)) {
//                 ans = (ans % MOD + (mul % MOD)) % MOD;
//             }
//         }
//     }
//     cout << ans << endl;
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int tt;
//     cin >> tt;
//     while (tt--) {
//         solve();
//     }
//     return 0;
// }

//m=3 and a=[4,2,2,3,6]


//find the no of magnificent arrays which are possible

// 1. no of elements = m
// 2. all (m) distinct elements : remove distinct elements :  we can use this later : the freq
// 3  abs diff between min and max in the array < m (<=m-1)


// for a given m 

// ai : level for the ith dancer 

// _ _ [_ _ _ _]_ _ _
//     l       r

// sort the arrays
// 1 2 3 4 5
// sliding wondow of size >= m and see if the top - bttom < size of the window if yes, then we can 
// // we can have a counter variable to multiply the count by the freq of duplicate elements

// 7 4
// 8 10 10 9 6 11 7

// 10 -> 2

// m = 4 : find number of magnificent dances

// 6 7 8 9 10 11

// [6,7,8,9] 1
// [7,8,9,10] 2
// [8,9,10,11] 2
// // we need to find the largest window of size >= m and top - min < m and pick m elements from it



// 12 3
// 5 2 1 1 4 3 5 5 5 2 7 5

// [1 2 3] 4 5 7
   

// [1,2,3] 1
// [2,3,4] 1 
// [3,4,5] 1



// 4,2,2,3,6

// 2,3,4,6

// [2,3,4] 3c3 * freq count = 2
// m = 3


long long mod  = 1e9+7;

void solve(){
  int n,m;
  cin >> n >> m;
  vector<int> a;
  map<long long,long long> freqMap;
  for(int i=0;i<n;i++) {
     int num;
     cin >> num;
     freqMap[num]++;
  }
  
  for(auto it : freqMap) a.push_back(it.first);
  
  
  // 1 2 3 .. m
  // diff between am-a1 < m that is window should have all consective elements
  long long cnt = 0;
  long long mul = 1;
  for(int i=0;i<a.size();i++){
    mul = (mul* freqMap[a[i]]) % mod;
    
    if(i>=m){
       //mul = mul/ freqMap[a[i-m]];
       mul = mod_div(mul, freqMap[a[i-m]]);
    }
    if( i>=m-1){
	    if(a[i] - a[i-m+1] < m){
           cnt = (cnt + mul) % mod;
        }
    } 
  }
  cout << cnt << endl;;
}


int main() {

  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}