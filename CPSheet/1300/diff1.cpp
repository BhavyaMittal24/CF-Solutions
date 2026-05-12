#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t; // Read the number of test cases
	while (t--) {
		int n;
		cin >> n; // Read the length of the array for the current test case
		vector<int> a(n, 0); // Initialize the array with n elements
		for (int i = 0; i < n; i++) { // O(n)
			cin >> a[i]; // Read each element of the array
		}

		vector<int> previous_different(n, -1); // Initialize a vector to store the index of the previous different element
		int prv = -1; // Variable to keep track of the last different element's index
		for (int i = 1; i < n; i++) { // O(n)
			if (a[i] != a[i - 1]) // Check if the current element is different from the previous one
				prv = i - 1; // Update the index of the last different element
			previous_different[i] = prv; // Store the index of the last different element
		}

		int q;
		cin >> q; // Read the number of queries
		while (q--) { // O(q)
			int l, r;
			cin >> l >> r; // Read the query boundaries
			if (previous_different[r - 1] >= l - 1) { // Check if there exists a different element within the range
				cout << r << " " << previous_different[r - 1] + 1 << endl; // Output the indices of the different elements
			} else {
				cout << -1 << " " << -1 << endl; // Output -1 -1 if no such pair exists
			}
		}
		cout << endl; // Separate outputs for different test cases
	}
}

// Time Complexity (TC): O(n+q)
// Space Complexity (SC): O(n)
