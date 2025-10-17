#include<bits/stdc++.h>
using namespace std;



// n,m <=1e5
// n is the stream of numbers in numerator ai
// m is stream of numbers in denominator bi

//  1<=ai,bi <=1e7

// Method is easy : for numbers a/b => to reduce them in their simplest forms 
// if a and b are coprime ie gcd(a,b) = 1, the nthey are already in their simplest form
// simplest form = a/gcd(a,b) / b/gcd(a,b)

// a = p1^k1 * p2^k2 * ... pn^kn
// b = p1^l1 * p2^l2 * ... pn^ln

// now to calculate their simplest form I can just subtract the powers of the common primes

// map to store the prime factors of a with p1 -> k1 (count /freq of p1) eg 24 = {2->3, 3->1}


// How to break down into the prime factors for a given number x
// option1 : 
// n can have atmost one prime factor > sqrt(n)
// so we can try to divide by all the primes <= sqrt(n) and if after that n > 1, then n is also a prime factor
// this approach would take o(sqrt(N) + logN) for each number :  sqrt(1e7) + log(1e7) = 3162 + 23 = 3185
// for the entire array, it would be 1e5 * 3185 : might give TLE

// We use Sieve of Eratosnes : and for all numbers between 1 to 1e17 (ai) I can find if it is prime or not, and if not prime i can find the smallest prime factor
// this will help decompose the number in o(log2 (1e7)) time 

// to do the entire process: for setting SPF = 0(Nlog(logN))


// assume all the numbers are prime and they are deactivating other numbers and markign them compisite, the number deactivated by a rpime will 
// have it's SPF as the prime

long long maxN = 1e7;
vector<long long> IsPrime(maxN+1, 1);
vector<long long> SPF(maxN+1,INT_MAX);

// SPF smallest prime factor rep SPF of any number betwee 1 to 1e7
// spf(i) + spf of i
// eg i = 8, spf(8)  = 2


void primeFactorisation(long long x, map<long long,long long> &primeFactors){
    while(x!=1){
        long long prime = SPF[x];
        long long power = 0;
        while( x % prime == 0){
            x = x/prime;
            power++;
        }
        primeFactors[prime] += power;
    }
    return;
}

long long binaryExponentiation(long long base, long long exp)
{
    long long res = 1;
    while(exp >0){
        if(exp &1){
            res= res*base;
        }
        base = base*base;
        exp = exp >>1;
    }
    return res;
}

int main(){

    for(long long i=2; i<=maxN;i++){
        if(IsPrime[i] == 1){
            SPF[i]= i;
            for(long long j=i*i;j<=maxN;j+=i){
                IsPrime[j] = 0;
                // eg 6 set by 2 and 3 : but 2 is spf(6)
                SPF[j] = min(SPF[j], i);
            }
        }
    }

    // Tc : o(Nlog(logN))

    long long n,m;
    cin >> n >> m;
    vector<long long> a(n);
    vector<long long> b(m);
    map<long long, long long> primeFactorsA;
    map<long long, long long> primeFactorsB;
    // let's have two maps for storing prime factors along with their counts
    for(int i=0;i<n;i++) {
        cin >> a[i];
        primeFactorisation(a[i], primeFactorsA);
    }
    for(int i=0;i<m;i++) {
        cin >> b[i];
        primeFactorisation(b[i], primeFactorsB);
    }

    for(auto it : primeFactorsA){
        long long prime = it.first;
        if(primeFactorsB.count(prime) > 0) {
        long long powerB = primeFactorsB[prime];
        long long powerA = it.second;

        if(powerA == powerB){
            primeFactorsA.erase(prime);
            primeFactorsB.erase(prime);
        }
        else if(powerA > powerB){
            primeFactorsA[prime] = powerA - powerB;
            primeFactorsB.erase(prime);
        }
        else {
            primeFactorsB[prime] = powerB - powerA;
            primeFactorsA.erase(prime);
        }
    }
    }

    cout << primeFactorsA.size() << " " << primeFactorsB.size() << endl;
    for(auto it : primeFactorsA){
        long long prime = it.first;
        long long power=  it.second;
        long long res = binaryExponentiation(prime,power);
        cout << res << " ";
    }
    cout << endl;

    for(auto it : primeFactorsB){
        long long prime = it.first;
        long long power=  it.second;
        long long res = binaryExponentiation(prime,power);
        cout << res << " ";
    }

    return 0;
}