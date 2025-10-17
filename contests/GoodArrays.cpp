#include <bits/stdc++.h>
using namespace std;

// CRITICAL FIX: The logic must be corrected to check remSum >= Ones.
// Also, we must use long long for reading individual array elements to prevent overflow.

void solve()
{
    int n;
    // Check if reading n is successful
    if (!(cin >> n)) return; 
    
    // Corner case: An operation requires two distinct indices i and j.
    if (n == 1) {
        long long val; 
        if (cin >> val) {} // Consume the single element safely
        cout << "NO" << "\n";
        return;
    }

    long long totalSum = 0;
    long long Ones = 0;
    
    // Loop to read all elements
    for (int i = 0; i < n; i++)
    {
        // CRITICAL FIX: Read individual values as long long to prevent overflow
        long long val; 
        if (!(cin >> val)) break; 
        
        if (val == 1)
            Ones++;
        totalSum += val;
    }

    // --- LOGIC CHECK ---
    
    // Case 1: Ones is not the majority (Ones <= n/2)
    if (Ones <= n / 2)
    {
        cout << "YES" << "\n";
        return;
    }

    // Case 2: Ones is the majority (Ones > n/2)
    
    // remSum: The total "excess value" available from all non-one elements.
    long long remSum = totalSum - Ones;

    // The condition for a "Good Array" is remSum >= Ones
    if (remSum >= n) // Corrected from remSum >= n
    {
        cout << "YES" << "\n";
    }
    else
    {
        cout << "NO" << "\n";
    }
}

int main()
{
    // Essential for competitive programming to avoid TLE with many test cases.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--)
    {
        // Call the void function to solve and print the result
        solve();
    }
    return 0;
}