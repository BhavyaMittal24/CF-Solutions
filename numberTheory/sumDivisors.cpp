// Sum of divisors

//  n= p1,k1 * p2,k2 * p3,k3 * … pnkn

// // PF form for the number is something of this sort

// // Multiple divisors

// // eg 20 = 2,2 * 5,1

// // number = 2+1 * (1+1)

// 1  2,0  5,0
// 2  2,1  5,0
// 4  2,2  5,0
// 5
// 10
// 20

long long m = 1e9 + 7;
#include <bits/stdc++.h>
using namespace std;

// a^b % m = a ^ (b %m-1) % m
long long binaryExp(long long base, long long exp)
{
    long long res = 1;
    while (exp > 0)
    {
        // if the rightmost bit is set, ie 1 i multiply the res by the base
        // initially the base is  1111 -> 15     a8 a4 a2 a
        // instead of doing it in 15 times, i convert this to binary rep and just use the bits

        if (exp & 1)
        {
            res = (res * base) % m;
        }
        base = (base * base) % m;
        exp = exp >> 1; // remove the rightmost bit
    }
    return res;
}

// get the PF format for the number in a map
// prime number

int main()
{
    long long n;
    cin >> n;

    // prime and their exponent
    map<long long, long long> mp;

    for (long long i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            long long prime = i;
            long exponent = 0;
            // 2^3 -> 2^2 -> 2^1 -> 1
            while (n % i == 0)
            {
                n = n / i;
                exponent++;
            }
            mp[prime] += exponent;
        }
    }
    if (n > 1)
    {
        mp[n] += 1;
    }

    //  a/b % m

    //   a ^ m-1 % m = 1 %m
    //   a ^ m - 2 = a-1 % m
    // store in a sorted format : tc : sqrt(n) + 0(logn)

    // (p1 ^ (k1+1) -1 ) (p1-1)

    // (2^3 - 1) * (3^2-1) / 2 = 7 * 8 /2 = 28
    long long res = 1;
    for (auto it : mp)
    {
        long long prime = it.first;
        long long exp = it.second;
        long long numerator = (binaryExp(prime, exp + 1) - 1 + m) % m;
        
        // Calculate modular inverse of (p-1)
        long long inv = binaryExp(prime - 1, m - 2) % m;

        // Multiply numerator by the modular inverse
        long long term_sum = (numerator * inv) % m;
        
        res = (res * term_sum) % m;
    }

    cout << res << endl;
    return 0;
}
