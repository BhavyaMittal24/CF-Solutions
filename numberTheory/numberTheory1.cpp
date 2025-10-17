// Number Theory for CP
#include<bits/stdc++.h>
using namespace std;



//Part 1 Factors for a given number
// 1. If there is a factor p, then another factor q exists in pairs for the number n (p,q)
// 2. The min(p,q) <= sqrt(n)

// To find sqrt (n) it takes log(N) time which adds extra complexity

int main()
{//TC : 0(sqrt(N)
for(int i=1;i*i<=n;i++){
   if(n % i==0) cout << i << " ";
}


// Part2 : Print all the prime factors for a given number 


// Brute force solution
// Find all the factors for the given factors for the number n
// In that n, for each factor find if the no of factors for it is exactly equal to 2. 
// TC : 0(N*srt(n)) 


// for each factor i, when n%i == 0 and to check prime
for(int i=1; i<=n;i++){
  if(n % i == 0 && isPrime(i)){
     ans.pb(i);
  } 
}

// Some important observations : a) for any number : the smallest factor is a prime number
// There can be only one prime factor which is > sqrt(N)
// p,q p*q = n .. and if one factor 
// any composite number or prime number is written in this form : n = p1^k1 * p2^ k2 * … pn ^ kn
// where p1, p2,.. pn are primes


set<int> st;
vector<pair<int,int>> primeFactorisation;
for(int d=2; d*d <=n;d++){  
    if( n%d ==0){
	st.insert(d);
    }
    int cnt = 0;
    // TC is the sum of powers : summation 2k = n
    while(n%d == 0) {
       n = n/d;
       cnt++;
    }
    primeFactorisation.push_back({d,cnt});
}

if(n > 1) {
   st.insert(n);
   primeFactorisation.push_back({n,1});
}
return 0;
}
