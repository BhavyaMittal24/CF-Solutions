#include <bits/stdc++.h>
using namespace std;

int main() {
	// Read the input string
	string s;
	cin >> s;

	// Get the size of the string
	int n = s.size();

	// Create a vector to store the result string
	vector<char> ans(n);

	// Initialize the first character of the result with the first character of the input
	ans[0] = s[0];

	// Iterate over the string starting from the second character
	for (int i = 1; i < n; i++) { // O(n)
		// If the current character is the same as the previous character in the result
		if (s[i] == ans[i - 1]) {
			// Try to find a different character to replace the current one
			for (char j = 'a'; j <= 'z'; j++) {
				// Ensure the new character is different from the previous one
				if (j != s[i - 1]) {
					// If not at the last character, ensure the new character is different from the next one
					if (i < n - 1 && j != s[i + 1]) {
						ans[i] = j;
						break;
					} else if (i == n - 1) { // If at the last character
						ans[i] = j;
						break;
					}
				}
			}
		} else {
			// If the current character is different from the previous one, keep it
			ans[i] = s[i];
		}
	}

	// Output the result string
	for (int i = 0; i < n; i++)
		cout << ans[i]; // O(n)
	cout << endl;

	return 0;
}

// Time Complexity (TC): O(n)
// Space Complexity (SC): O(n)
