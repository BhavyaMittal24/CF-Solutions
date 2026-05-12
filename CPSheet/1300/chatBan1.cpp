#include <bits/stdc++.h>
using namespace std;

// Function to calculate the sum of the first x natural numbers
long long calculateSumOfFirstX(int x) {
	return x * 1ll * (x + 1) / 2;
}

int main() {
	int t;
	cin >> t; // Read the number of test cases
	while (t--) { // Iterate over each test case
		long long int k, x;
		cin >> k >> x; // Read the values of k and x for the current test case

		// Initialize binary search boundaries
		long long int lo = 1, hi = 2 * k - 1, ans = 2 * k - 1;

		// Perform binary search to find the number of messages before getting banned
		while (lo <= hi) {
			long long int mid = (lo + hi) / 2; // Calculate the middle point
			long long int cnt;

			// Calculate the number of emotes sent if mid is greater than or equal to k
			if (mid >= k) {
				cnt = calculateSumOfFirstX(k) + calculateSumOfFirstX(k - 1) - calculateSumOfFirstX(2 * k - 1 - mid);
			} else {
				// Calculate the number of emotes sent if mid is less than k
				cnt = calculateSumOfFirstX(mid);
			}

			// Check if the number of emotes sent is greater than or equal to x
			if (cnt >= x) { // We get banned
				ans = mid; // Update the answer
				hi = mid - 1; // Narrow the search to the lower half
			} else {
				lo = mid + 1; // Narrow the search to the upper half
			}
		}

		// Output the result for the current test case
		cout << ans << endl;
	}
}

// Time Complexity (TC): O(t * log(k))
// Space Complexity (SC): O(1)
