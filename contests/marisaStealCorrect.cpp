#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;

    int count0 = 0, count1 = 0, count2 = 0;

    for (int i = 0; i < n; i++) {
        int w;
        cin >> w;
        if (w == 0) count0++;
        else if (w == 1) count1++;
        else if (w == 2) count2++;
    }

    long long max_operations = 0;

    max_operations += count0;

    int pairs = min(count1, count2);
    max_operations += pairs;

    count1 -= pairs;
    count2 -= pairs;

    max_operations += (count1 / 3);

    max_operations += (count2 / 3);

    cout << max_operations << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    } else {
        solve();
    }
    return 0;
}