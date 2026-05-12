#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
	// Read the input string consisting of 'v' and 'o'
	string s;
	cin >> s;

	// Get the length of the string
	int n = s.size();

	// Initialize a DP table with dimensions (n+1) x 4, filled with zeros
	// dp[i][0] - Tracks the number of subsequences ending at i that can start a 'wow'
	// dp[i][1] - Tracks subsequences that have formed 'w'
	// dp[i][2] - Tracks subsequences that have formed 'wo'
	// dp[i][3] - Tracks subsequences that have formed 'wow'
	vector<vector<int>> dp(n + 1, vector<int>(4, 0));

	// Initialize the base case: every position can start a new subsequence
	for (int i = 0; i < n; i++) { // O(n)
		dp[i][0] = 1;
	}

	// Iterate over the string to fill the DP table
	for (int i = 1; i < n; i++) { // O(n)
		if (s[i] == 'v' && s[i - 1] == 'v') {
			// If we find 'vv', it can be considered as 'w'
			dp[i + 1][1] += dp[i - 1][0]; // Transition to 'w'
			dp[i + 1][3] += dp[i - 1][2]; // Transition to 'wow'
		} else if (s[i] == 'o') {
			// If we find 'o', it can continue a 'wo' subsequence
			dp[i + 1][2] += dp[i][1]; // Transition to 'wo'
		}
		// Carry forward the counts for each state
		dp[i + 1][1] += dp[i][1];
		dp[i + 1][2] += dp[i][2];
		dp[i + 1][3] += dp[i][3];
	}

	// Output the total number of 'wow' subsequences
	cout << dp[n][3] << endl;
	return 0;
}

// Time Complexity (TC): O(n)
// Space Complexity (SC): O(n)
