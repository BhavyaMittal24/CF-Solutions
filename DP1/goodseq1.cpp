#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std;

// Function to find all divisors of a number x
vector<int> get_divisors(int x) {
    vector<int> divisors;
    // Iterate up to sqrt(x)
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            divisors.push_back(i);
            if (i * i != x) {
                divisors.push_back(x / i);
            }
        }
    }
    // The number itself is also a divisor
    if (x > 1) {
        divisors.push_back(x);
    }
    return divisors;
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    int max_val = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        max_val = max(max_val, arr[i]);
    }

    // d[i]: Max length of a good sequence ending with a number divisible by i.
    // Max value is 10^5 + 1
    vector<int> d(max_val + 1, 0); 
    int max_len = 1;

    for (int x : arr) {
        // Handle the corner case for x=1: divisors > 1 is empty, length is 1.
        if (x == 1) {
            // d[1] will be updated to 1, which works for all subsequent numbers.
            d[1] = 1;
            continue;
        }

        vector<int> divisors = get_divisors(x);
        int L = 0;
        
        for (int i : divisors) {
            L = max(L, d[i]);
        }
        
        int dp_x = 1 + L;
        max_len = max(max_len, dp_x);

        // 3. Update d[i] for all divisors i (including 1)
        
        for (int i : divisors) {
            d[i] = max(d[i], dp_x);
        }
    }
    
    // The answer is the overall max_len found
    cout << max_len << endl;
}

int main() {
    // For local testing:
    // The provided example: 2 3 4 6 9
    // Expected max length: [2, 4, 6, 9] or [3, 6, 9] -> length 4
    // solve(); 
    solve();
    return 0;
}