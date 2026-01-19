#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t; // Read number of test cases

	while (t--) {
		int n;
		cin >> n; // Read the size of the array

		vector<int> v(n); // Input vector

		// Read all elements into the vector
		for (int i = 0; i < n; i++)
			cin >> v[i]; // O(N)

		map<int, int> cnt; // Frequency map to count occurrences of each number

		// Populate frequency map
		for (int i = 0; i < n; i++)
			cnt[v[i]]++; // O(N log N) due to map insertion

		int ans = 0; // Final answer

		// Calculate result based on frequency difference with previous element
		for (auto &[ele, fre] : cnt) {
			// ele = current element
			// fre = frequency of current element
			// max(0, current frequency - previous frequency)
			ans += max(0, cnt[ele] - cnt[ele - 1]);
		}
		// O(N log N) due to iterating over sorted map

		cout << ans << "\n"; // Output result
	}

	return 0;
}

// Time Complexity (TC): O(N log N)
// Space Complexity (SC): O(N)

