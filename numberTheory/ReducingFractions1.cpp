#include<bits/stdc++.h>
using namespace std;

long long maxN = 1e7;
vector<long long> IsPrime(maxN+1, 1);
vector<long long> SPF(maxN+1);

void primeFactorisation(long long x, map<long long,long long> &primeFactors){
    while(x != 1){
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
    while(exp > 0){
        if(exp & 1){
            res = res * base;
        }
        base = base * base;
        exp = exp >> 1;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // Sieve of Eratosthenes to precompute Smallest Prime Factor (SPF)
    for(long long i=1; i<=maxN; i++) {
        SPF[i] = i;
    }
    
    // Corrected and optimized Sieve
    for(long long i=2; i*i<=maxN; i++){
        if(IsPrime[i] == 1){
            for(long long j=i*i; j<=maxN; j+=i){
                if(IsPrime[j] == 1){
                    IsPrime[j] = 0;
                    SPF[j] = i;
                }
            }
        }
    }

    long long n,m;
    cin >> n >> m;
    map<long long, long long> primeFactorsA;
    map<long long, long long> primeFactorsB;
    map<long long, long long> p;
    
    vector<long long> a(n,0);
    vector<long long> b(m,0);
    for(int i=0; i<n; i++) {
        cin >> a[i];
        primeFactorisation(a[i], primeFactorsA);
    }
    for(int i=0; i<m; i++) {
        cin >> b[i];
        primeFactorisation(b[i], primeFactorsB);
    }

    // // Safely iterate and modify maps to subtract common factors
    // for(auto it = primeFactorsA.begin(); it != primeFactorsA.end(); ) {
    //     long long prime = it->first;
    //     if(primeFactorsB.count(prime) > 0) {
    //         long long powerA = it->second;
    //         long long powerB = primeFactorsB[prime];

    //         if(powerA == powerB) {
    //             it = primeFactorsA.erase(it);
    //             primeFactorsB.erase(prime);
    //         } else if(powerA > powerB) {
    //             it->second = powerA - powerB;
    //             primeFactorsB.erase(prime);
    //             ++it;
    //         } else { // powerA < powerB
    //             primeFactorsB[prime] = powerB - powerA;
    //             it = primeFactorsA.erase(it);
    //         }
    //     } else {
    //         ++it;
    //     }
    // }

    for(auto it :primeFactorsA){
        p[it.first] = min(primeFactorsA[it.first], primeFactorsB[it.first]);
    }

    primeFactorsA = primeFactorsB = p;
    // total factors hich need to be remvoved both num and den
    for(int i=0;i<a.size();i++){
        long long x = a[i];
        while(x !=1){
            long long prime = SPF[x];
            long long cnt = 0;
            while(x % prime == 0){
                x= x/prime;
                cnt++;
            }
            cnt = min(cnt, primeFactorsA[prime]);
            primeFactorsA[prime] -= cnt;
            while(cnt --){
                a[i] = a[i]/prime;
            }
        }
    }

    for(int i=0;i<m;i++){
        int x = b[i];
        while(x !=1){
            long long prime = SPF[x];
            long long cnt = 0;
            while(x % prime == 0){
                x = x/prime;
                cnt++;
            }
            cnt = min(cnt, primeFactorsB[prime]);
            primeFactorsB[prime] -= cnt;
            while(cnt --){
                b[i]= b[i]/prime;
            }
        }
    }
   
    cout << a.size() << " " << b.size() << endl;

    for(auto i : a) cout << i << " ";
    cout << endl;
    for(auto i : b) cout << i << " ";
    cout << endl;

    return 0;
}