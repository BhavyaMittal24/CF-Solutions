#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> freq;
    int absolute_max = -1;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
        absolute_max = max(absolute_max, a[i]);
    }

    // Array to hold our custom rearrangement
    vector<int> final_arr;

    // STEP 1: Place the absolute maximum element first
    if (absolute_max != -1) {
        final_arr.push_back(absolute_max);
        freq[absolute_max]--;
        if (freq[absolute_max] == 0) {
            freq.erase(absolute_max);
        }
    }

    // STEP 2: Place the sequential MEX block (0, 1, 2...) next
    int current = 0;
    while (freq[current] > 0) {
        final_arr.push_back(current);
        freq[current]--;
        if (freq[current] == 0) {
            freq.erase(current);
        }
        current++;
    }

    // STEP 3: Place all the remaining leftovers at the end
    for (auto const& [val, count] : freq) {
        for (int i = 0; i < count; i++) {
            final_arr.push_back(val);
        }
    }

    // -------------------------------------------------------------
    // Evaluation Pass: Calculate the prefix MAX and MEX sums
    // -------------------------------------------------------------
    long long total_sum = 0;
    int current_max = -1;
    
    // SAFE: Using std::set (Red-Black Tree structure) to protect against hash hacks
    set<int> seen;
    int current_mex = 0;

    for (int i = 0; i < n; i++) {
        current_max = max(current_max, final_arr[i]);
        seen.insert(final_arr[i]);
        
        // Dynamic MEX pointer progression
        while (seen.count(current_mex)) {
            current_mex++;
        }
        
        total_sum += (1ll * current_max + current_mex);
    }

    cout << total_sum << "\n";
}

int main() {
    // Optimize standard I/O streams for competitive programming speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}