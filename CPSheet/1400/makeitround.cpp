#include <bits/stdc++.h>

using namespace std;

long long p2[19];
long long p5[19];

void solve() {
		int n, m;
		cin >> n >> m;

		int c2 = 0, c5 = 0; // counts of factor 2 and 5 in n

		int temp = n;
		while (temp % 2 == 0) {
				c2++;      // count how many times 2 divides n
				temp /= 2;
		}

		temp = n;
		while (temp % 5 == 0) {
				c5++;      // count how many times 5 divides n
				temp /= 5;
		}

		// Try to achieve dig trailing zeros in n * k (from high to low),
		// by ensuring k contributes enough 2s and 5s.
		for (int dig = 18; dig >= 0; dig--) {
				int extra2 = max(0, dig - c2); // how many extra 2s k must supply
				int extra5 = max(0, dig - c5); // how many extra 5s k must supply

				// Minimal factor that ensures at least 'dig' trailing zeros when multiplied by n
				long long need = p2[extra2] * p5[extra5];
				if (need <= m) {
						// Choose the largest k <= m that is divisible by 'need' to maximize n * k
						int largestK = m - m % need;
						cout << 1LL * largestK * n << '\n';
						return;
				}
		}
}

int main() {
		cin.sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		p2[0] = 1;
		p5[0] = 1;

		// Precompute powers of 2 and 5 up to 18 to cover needed extra factors
		for (int i = 1; i <= 18; i++) {
				p2[i] = 2 * p2[i - 1];
				p5[i] = 5 * p5[i - 1];
		}

		int t;
		cin >> t;
		while (t--) {
				solve();
		}
}
