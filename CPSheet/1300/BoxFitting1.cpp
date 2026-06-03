#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; 
	cin >> t; // Read the number of test cases
	while (t--) {
		int n, w; 
		cin >> n >> w; // Read the number of rectangles and the width of the box for each test case
		vector<int> a(n);
		for (int i = 0; i < n; i++) { // O(n)
			cin >> a[i]; // Read the width of each rectangle
		}
		vector<int> widthCount(21, 0); // Initialize a vector to count the occurrences of each power of 2 width
		for (int i = 0; i < n; i++) { // O(n * log(a[i]))
			int logVal = log2(a[i]); // Calculate the power of 2 for the current rectangle width
			widthCount[logVal]++; // Increment the count for this power of 2
		}
		int height = 0; // Initialize the height of the box
		int countOfUsedBoxes = 0; // Initialize the count of rectangles that have been placed in the box
		while (countOfUsedBoxes < n) { // O(n * log(a[i]))
			int temp = w; // Start with the full width of the box
			for (int i = 20; i >= 0; i--) { // Check from the largest power of 2 to the smallest
				while (widthCount[i] > 0 && (1 << i) <= temp) { // While there are rectangles of this width and they fit in the remaining width
					temp -= (1 << i); // Reduce the remaining width by the width of the rectangle
					widthCount[i]--; // Decrease the count of this width
					countOfUsedBoxes++; // Increase the count of used rectangles
				}
			}
			height++; // Increase the height of the box as a new row is used
		}
		cout << height << endl; // Output the minimum height of the box for the current test case
	}
}

// Time Complexity (TC): O(n * log(a[i]))
// Space Complexity (SC): O(n)
