// Problem Statement
// Given is a positive integer
// N. Consider repeatedly applying the operation below on
// N:

// First, choose a positive integer
// z satisfying all of the conditions below:
// z can be represented as
// z=p e
//  , where
// p is a prime number and
// e is a positive integer;
// z divides
// N;
// z is different from all integers chosen in previous operations.
// Then, replace
// N with
// N/z.
// Find the maximum number of times the operation can be applied.

// Constraints
// All values in input are integers.
// 1≤N≤10
// 12

// 24
// z = p^e where p is prime and e is positive integer (1,2,)

// 1. z not equal to 1
// 2. in each iteration pick another number different from z

// 24

// 12

// 4
// 2->3->4

// 24
// Sample Output 1
// Copy
// 3
// We can apply the operation three times by, for example, making the following choices:

// Choose
// z=2(=2
// 1
//  ). (Now we have
// N=12.)
// Choose
// z=3(=3
// 1
//  ). (Now we have
// N=4.)
// Choose
// z=4(=2
// 2
//  ). (Now we have
// N=1.)

// n = 1e12
// N = prime factorisation of N

// n = p1 k1, p2, k2,  p3k3, p4k4, p5k5 ... pmkm

// // I would need to keep dividing by the factirs,
// // 2 1, then 3 1, 2 2, ... so in this order nd cnt till i get 1
// no of factors of a number n= cbrt(n) = 1e4
// // store all the factors in a set exclusing 1
// and keep dividing until you get 1

// no of distinct factors which are minimum as I need to maximise the answer

#include <bits/stdc++.h>
using namespace std;

int main()
{

    // prime number : 1e9 +7
    long long n;
    cin >> n;

    set<long long> factors;
    factors.insert(n);
    // We dont divide by z = 1;

    // no of factors of n = cbrt(N)
    // n == 1e12

    // 1e6 * LOG(1E4) = 
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            factors.insert(i);
            factors.insert(n / i);
        }
    }

    long long cnt = 0;
    while (n > 1 && !factors.empty() && n >= *factors.begin())
    {
        long long smallestFactor = *factors.begin();
        n = n / smallestFactor;
        factors.erase(smallestFactor);
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}

// 12
// 2,3,4,6,12

// 12 6 2
// 2  3 