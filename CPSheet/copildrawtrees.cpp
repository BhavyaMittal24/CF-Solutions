// . Copil Copac Draws Trees#include <bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;                // adjacency list of the tree (0-indexed)
vector<int> dp;                         // dp[v] = readings needed to reach v from root
map<pair<int, int>, int> ind;           // input order index for each directed edge (u -> v)

void dfs(int vert, int par) {
	for (auto x : adj[vert]) {
		if (x == par) continue;            // avoid traversing back to parent

		// If the edge to child appears later in the input order than the edge to this node,
		// it can be drawn in the same reading; otherwise, it starts a new reading.
		if (ind[{par, vert}] < ind[{vert, x}]) {
			dp[x] = dp[vert];
		} else {
			dp[x] = dp[vert] + 1;
		}
		dfs(x, vert);
	}
}

void solve() {
	int n;
	cin >> n;
	adj.assign(n, vector<int>());
	dp.assign(n, 0);
	ind.clear();

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		--a, --b;                          // convert to 0-based indices
		adj[a].push_back(b);
		adj[b].push_back(a);
		ind[{a, b}] = i;                   // store input order for both directions
		ind[{b, a}] = i;
	}

	ind[{-1, 0}] = -1;                    // sentinel: parent of root has edge index -1

	dp[0] = 1;                            // first reading starts when we draw the root
	dfs(0, -1);

	cout << *max_element(dp.begin(), dp.end()) << '\n';
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}

/*
Time Complexity (TC): O(nlogn)
Space Complexity (SC): O(n)
*/
