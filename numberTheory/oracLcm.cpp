// a1 a2 …. an  1<=ai <= 2e5

// <2 = n <= 1e5 



// lcm (a1,a2) ..  lcm (a1, an) , lcm(a2,a3) ….

// find gcd (all the lcms) 

// number of factors for a number n : less than sqrt(n) : cbrt(n)


// number of prime factors <= number n : ~ n/ loge(n)
// [2,3, ..7, 11, 13 … n] 

// sieve : NLog2(log(N))

// prime factorisation for all the numbers

// let's go prime wise : prime by prime
//     a1  a2 a3 a4
// p1  k1  k2 k3 k4

// lcm k2  k3 k4 k3 k4 k4

// gcd = min = k2 :
// so for each prime number you get the second largest power in the array for numbers
// // pf for each numner : log(ai) = 


// sive = spf of all numbers <= 2e5 : ai : 1e5 log(log(1e5)
// n : numbers : each can have some power for a prime factor p:

// // inserting in the 2d array of vector of powers of primes : for each ai : N * log(ai)
// prime factor wise : 2e5 * 1e5
// factors actrually are cbrt(2e5) ~ <=100 primes * powers for ech prime ~ 1e5 == 1e7 

#include<bits/stdc++.h>
using namespace std;
const int maxN = 200001;
vector<int> spf(maxN);

//vector for all prime numbers between 1 to 2e5 (max value of ai): which store the powers for the prime for each ai 
vector< vector<int> > primes(maxN+1);

void sieve(){
  for(int i=0;i<maxN;i++) spf[i] = i;
  // assuming all numbers are prime initially
  for(long long i=2;i<maxN;i++){

     if(spf[i] == i){
      	for(long long j=i*i;j<maxN; j+=i){
          spf[j] = min(spf[j], (int)i);
        } 
     }
  } 
}

void pf(int a){
  while(a != 1){
     int prime = spf[a];
     int count = 0;
     while( a % prime == 0){
        a = a / prime;
        count++;
     }
     primes[prime].push_back(count);
  }
}

int main(){
  sieve();
  int n;
  cin >> n;

  // nof of primes factors between 1 to 2e5  =  2e5 / loge(2e5) ~ 4* 1e4 / loge(20) 1.33 * 1e4 ~ 13300
  vector<int> a(n);
  for(int i=0;i<n;i++){
  	cin >> a[i];
    pf(a[i]);
  }
   

  // number of primes upto 2e5 : 2e5/ log(2e5 ~ 2e5/5*log(20) ~  4 * 1e4 /  4 ~ 1e4
  // sort them : 1e5log(1e5) 5 * 1e5 
  long long gcd = 1;
  for(int i =2;i<maxN;i++){
     vector<int> powers = primes[i];
     sort(powers.begin(), powers.end());
     if(powers.size() < n-1 ) continue; 
     if( powers.size() == n) gcd = gcd * pow(i,powers[1]);
     else gcd = gcd * pow(i,powers[0]);
  }

  cout << gcd << endl;
  return 0;

}

// 4 7 9 20
// 18
// 630

// 2 2,0,0,2,2   2^2  2
// 3, 0,0,2,0,2  3^2  9
// 7, 0,1,0,0,0  7^1  7
// 5,0,0,0,1,0   5^1  5


