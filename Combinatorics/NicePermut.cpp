#include<bits/stdc++.h>
using namespace std;

const long long mod =  998244353;

// N is of the order : 1e6
// we can precompute all the ncr in 0(1)
// ncr = n! *  inv (n-r)! * inv(r!)

// we can precompute factorial and inverse factorial in 0(n) using mod;

long long maxN = 200001;


// 5^ 9
// 5^ 1001

// 1      0    0    1
// 5^8  5^4   25    5
// Tc is  o(log2(exponent))
long long binaryExp( long long base, long long exp){
    base = base % mod;
    long long res =1;
    while(exp>0){
       if(exp & 1){
          res = (res * base) % mod;
       }
       base = (base * base) % mod;
       exp = exp >>1; // remove the rightmost bit
    }
   return res;
}


vector<long long> factorial(maxN+1,1);

vector<long long> invFactorial(maxN+1,1);

void precompute(){
   for(int i=1;i<=maxN;i++){
      factorial[i] =  ( i*factorial[i-1] ) % mod;
   }
   // inv (n-1!) = n * inv(n!)
    // a^m-2 = a-1

    // FERMAT'S LITTLE THEOREM
    // a^(p-1) = 1 mod p when p is a prime number
   long long invNFactorial = binaryExp(factorial[maxN],mod-2);
    invFactorial[maxN] = invNFactorial;
   for(int i= maxN-1;i>=1;i--){
       invFactorial[i] = ( (i+1)* invFactorial[i+1]) % mod;
    }
 
}

// ncr = N! / (R! * (N-R)!)
long long answer(long long n, long long r){
    long long num = factorial[n];
    long long den = (invFactorial[r] * invFactorial[n-r]) % mod;
    long long res = (num * den) % mod;
    return res;
}

void solve(){
  int n;
  cin >> n;
  map<int,int> freq;
  int maxElement = 0;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        maxElement = max(maxElement, x);
        freq[x]++;
    }

    if(freq[maxElement] > 1){
        cout << factorial[n] << endl;
        return;
    }
    

    if( freq.find(maxElement -1) == freq.end() ){
        cout << 0 << endl;
        return;
    }

    int countMaxMinus1 = freq[maxElement -1];

    long long ans = 0;
    
    for(int i=1;i<n;i++){

        if( countMaxMinus1 >= i){
            ans = (ans + factorial[n-1]) % mod;
        }
        else {
            // when the freq(x-1) < i : total ways to arrange when x is at pos i
            long long totalways = factorial[n-1];

            // total invalid ways when x-1 is before x at pos 1 to i-1
            // i-1 C f(x-1) * f(x-1)! * ( n - 1 - f(x-1))!
            long long invalidWays = ( factorial[n-1-countMaxMinus1] * factorial[countMaxMinus1] ) % mod;
            invalidWays = ( invalidWays * answer(i-1, countMaxMinus1) ) % mod;
            long long validWays = ( totalways - invalidWays + mod ) % mod;
            ans = (ans + validWays) % mod;
        }
    }
    cout << ans % mod << endl;
}
int main(){
    int t;
    cin >> t;
    precompute();
    while(t--){
        solve();
    }
}