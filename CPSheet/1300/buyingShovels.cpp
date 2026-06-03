#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t; // Read the number of test cases
	while (t--) { // Loop over each test case
		int n, k;
		cin >> n >> k; // Read the number of shovels and the number of types of packages
		int ans = n; // Initialize the answer to the maximum possible number of packages

		// Iterate over possible package sizes
		for (int j = 1; j * j <= n; j++) { // Check divisors up to the square root of n
			if (j > k) break; // If the package size exceeds k, break the loop

			if (n % j == 0) { // If j is a divisor of n
				ans = min(ans, n / j); // Update the answer with the minimum number of packages

				// Check the complementary divisor
				if (n / j <= k)
					ans = min(ans, j); // Update the answer if the complementary divisor is a valid package size
			}
		}

		cout << ans << endl; // Output the minimum number of packages for this test case
	}
}

// Time Complexity (TC): O(T * sqrt(n)) = 10^6
// Space Complexity (SC): O(1)
