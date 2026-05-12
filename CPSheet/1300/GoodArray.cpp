#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
	int n;
	cin >> n; // Read the number of elements in the array
	vector<int> a(n); // Initialize the array to store elements
	vector<int> counts(1e6 + 1, 0); // Initialize a frequency array for elements up to 1e6
	int sum = 0; // Variable to store the sum of all elements

	// Read the array elements and calculate their sum
	for (int i = 0; i < n; i++) { // O(n)
		cin >> a[i]; // Read each element
		counts[a[i]]++; // Increment the count of the current element
		sum += a[i]; // Add the current element to the sum
	}

	vector<int> answers; // Vector to store indices of elements that can be removed to make the array good

	// Check each element to see if its removal makes the array good
	for (int i = 0; i < n; i++) { // O(n)
		int newSum = sum - a[i]; // Calculate the sum of the array without the current element
		counts[a[i]]--; // Temporarily decrement the count of the current element

		// Check if the new sum is even and if half of it exists in the array
		if (newSum % 2 == 0 && (newSum / 2) <= 1e6 && counts[newSum / 2] > 0) {
			answers.push_back(i + 1); // Store the 1-based index of the element
		}

		counts[a[i]]++; // Restore the count of the current element
	}

	// Output the number of nice indices
	cout << answers.size() << endl;
	// Output the nice indices
	for (int i : answers) cout << i << " "; // O(n)
	cout << endl;
}

// Time Complexity (TC): O(n + 1e6)
// Space Complexity (SC): O(n + 1e6)
