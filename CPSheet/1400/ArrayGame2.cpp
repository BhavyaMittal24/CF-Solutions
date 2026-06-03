#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	long long a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// With 3 or more operations we can always make the minimum 0.
	// (Construct 0 by appending equal numbers via differences.)
	if (k >= 3) {
		cout << 0 << '\n';
		return;
	}

	vector<long long> differences; // O(n^2) space to store all pairwise |ai - aj|

	// Generate all pairwise absolute differences that can appear after one operation.
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			differences.push_back(abs(a[i] - a[j]));
		}
	}

	// Sort to allow binary search for the closest difference.
	sort(differences.begin(), differences.end()); // O(n^2 log n)

	long long ans = LLONG_MAX;

	// Baseline: current minimum value in the array (0 operations used yet).
	for (int i = 0; i < n; i++) {
		ans = min(ans, a[i]);
	}

	// After one operation, we can append any |ai - aj|; the best is the smallest such value.
	ans = min(ans, differences[0]);

	if (k == 2) {
		// With two operations: first append some d in differences, then append |ai - d|.
		// The best achievable is min over i of the closest d to ai, i.e., minimize |ai - d|.
		for (int i = 0; i < n; i++) {
			auto it = lower_bound(differences.begin(), differences.end(), a[i]); // find first d >= ai
			if (it != differences.end()) {
				ans = min(ans, abs(*it - a[i]));
			}
			if (it != differences.begin()) {
				--it; // check the closest d < ai
				ans = min(ans, abs(*it - a[i]));
			}
		}
	}

	cout << ans << '\n';
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}

/*
Time Complexity (TC): O(n^2 log n)
Space Complexity (SC): O(n^2)
*/
