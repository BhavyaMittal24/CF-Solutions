// Number Theory 2

//In q queries, given a number x, tell if it's prime or composite

// x,q <= 1e6
// To tell If a number is prime or composite, it should have the prime factorisation of the nuber as {number,1}
// This can be done in o(log2n + sqrt(n)) 


// Sieve of Eratosthenes : Use that technique to prepare the sieve


// Make an array for I = 1 to I = x as x can be between 1 to 1e6
// isprime[i] = 1 : Prime,
// isPrime[i] = 0 : COmposite

// Assume all the values are prime initially, and then we set it to composite


int maxN = 1e6;
// 2 --> 4 - 6 - 8 --
vector<int> arr(N+1,1);

for(int i=2; i<= N;i++){
 
  // we found a prime number : let's deactivate other numbers
  if(isPrime[i] == 1){
     for(int j=i* i;j<=N; j+=i){
     	  // MARKING THEM AS COMPOSITE
          isPrime[j] = 0;
	}
  }
}

tC : o(N logN)

// sum of  : 
// operqtions when i = 2 , : N/2
//                 i = 3,  : n/3 


// TC : Nlog(logN)

// The first number any p deactivates is p^2 ?
// WHy?

//  p  2p 3p         (p-2)*p  p-1*p   p^2
//  x can be [2p, (p-1)*p)

//  x < p^2
//  p > sqrt(x)
//  p' < p 
//  p' <= sqrt(x)
//  p' * p' <= x



//Now, if we are given the same question but to find the prime factorisation for the given number x

// x,q <= 1e6

// for q wuerues, for each x, give the PF of x 

// for x, the PF is given by finding all the smallest factors upto Sqrt(n) and dividing by their powers 
// tc : ( o(sqrt(n) + o(log2N)

// We can have something prepared called as the smallest prime factor SPF : eg p = p1^k1 &* p2^k2 
// SPF = p1 for the number p



int maxN = 1e6;
// 2 --> 4 - 6 - 8 --
vector<int> arr(N+1,1);

vector<int> SPF(maxN+1, 1e6);

for(int i=2; i<= N;i++){
 
  // we found a prime number : let's deactivate other numbers
  if(isPrime[i] == 1){
     // for  a prime, it's spf is itself
     SPF[i] = i;
     for(int j=i* i;j<=N; j+=i){
     	  // MARKING THEM AS COMPOSITE
          isPrime[j] = 0;
          SPF[j] = min(SPF(j), i);
	}
  }
}

// Now for a given number x : we want it's prime factorisation 

vector<pair<int,int>> primeFactorisation(int x){
 
    while(x !=1){
       int prime = spf[x];
       int cnt = 0;
       while( x % prime == 0) {
          x = x/prime;
          cnt ++;
	}
       primeFactorisation({prime,cnt});
    }
   return primeFactorisation
}

