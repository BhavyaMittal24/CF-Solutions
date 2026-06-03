#include <bits/stdc++.h>
using namespace std;

int main() {
	// Read the number of days (n) and the length of a week (k)
	int n, k;
	cin >> n >> k;

	// Initialize a vector to store sleep times for each day
	vector<int> v(n, 0);

	// Variable to store the total sum of sleep times over all weeks
	long long total_sum = 0;

	// Read the sleep times for each day
	for (int i = 0; i < n; i++) { // O(n)
		cin >> v[i];
	}

	// Calculate the sum of sleep times for the first 'k' days
	long long sum = 0;
	for (int i = 0; i < k; i++) { // O(k)
		sum += v[i];
	}

	// Initialize total_sum with the sum of the first 'k' days
	total_sum = sum;

	// Initialize two pointers for the sliding window
	int p1 = 0, p2 = k;

	// Slide the window across the array to calculate the sum for each week
	while (p2 < n) { // O(n-k)
		// Subtract the element going out of the window
		sum -= v[p1];
		// Add the new element coming into the window
		sum += v[p2];
		// Add the current window sum to total_sum
		total_sum += sum;
		// Move the window forward
		p1++;
		p2++;
	}

	// Output the average sleep time over all weeks with a precision of 6 decimal places
	cout << fixed << setprecision(6) << 1.0 * total_sum / (n - k + 1) << endl;
}

// Time Complexity (TC): O(n+k)
// Space Complexity (SC): O(n)
