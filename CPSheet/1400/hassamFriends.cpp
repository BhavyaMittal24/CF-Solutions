#include <bits/stdc++.h>
using namespace std;

void solve() {
		int n, m;
		cin >> n >> m;

		// nearestEnemy[i]: for right endpoint i, the largest j < i such that (j, i) is a non-friend (0 if none)
		vector<int> nearestEnemy(n + 1, 0);

		for (int i = 0; i < m; i++) {
				int a, b;
				cin >> a >> b;
				if (a > b) swap(a, b);               // ensure a < b so we map by the right endpoint b
				nearestEnemy[b] = max(nearestEnemy[b], a); // for subarrays ending at b, start must be > a
		}

		// maxLeft[i]: smallest valid starting index for any good subsegment that ends at i
		vector<int> maxLeft(n + 1);

		maxLeft[1] = 1; // subsegments ending at 1 must start at least from 1

		long long ans = 1; // counts the subsegment [1, 1]

		for (int i = 2; i <= n; i++) {
				// Can't start before the previous bound (monotonic), and must be after the last enemy of i
				maxLeft[i] = max(maxLeft[i - 1], nearestEnemy[i] + 1);
				// Number of good subsegments ending at i is the number of valid starts in [maxLeft[i], i]
				ans += i - maxLeft[i] + 1;
		}

		cout << ans << '\n';
}

int main() {
		cin.sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int t;
		cin >> t;
		while (t--) {
				solve();
		}
}

/*
Time Complexity (TC): O(n + m)
Space Complexity (SC): O(n)
*/
