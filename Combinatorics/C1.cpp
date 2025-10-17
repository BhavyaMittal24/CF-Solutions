// Combinatorics and Probability

// ncr  : Choose r elements out of n

#include <bits/stdc++.h>
using namespace std;

// a good practice to have the mod as a constant. If it is a variable, the address is read again and again, instead of being cached

const long long mod = 1e9+7;

// N is of the order : 1e6
// we can precompute all the ncr in 0(1)
// ncr = n! *  inv (n-r)! * inv(r!)

// we can precompute factorial and inverse factorial in 0(n) using mod;

long long maxN = 10;


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
      factorial[i] = i*factorial[i-1];
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

int main(){
  precompute();
  int n;
  int r;
  cin >> n >> r;
  long long ans = answer(n,r);
  cout << ans << endl;

  return 0;
}