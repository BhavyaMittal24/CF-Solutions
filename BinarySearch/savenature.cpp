#include <iostream>
#include <vector>
#include <numeric> // For std::gcd
#include <algorithm> // For std::sort and std::reverse

using namespace std;

// Function to calculate greatest common divisor
long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

// Function to check if a given number of tickets can yield the required profit
bool isPossibleToSellWithProfitK(int tickets, int a, int b, int x, int y, long long k, const vector<int>& p) {
    if (tickets == 0) return 0 >= k;

    long long totalProfit = 0;
    
    // To simplify logic, ensure x is always the larger percentage
    if (x < y) {
        swap(x, y);
        swap(a, b);
    }
    
    // Calculate LCM to handle tickets divisible by both a and b
    long long lcm_ab = (1LL * a * b) / gcd(a, b);
    
    // Number of tickets for each profit category
    long long count_ab = tickets / lcm_ab;
    long long count_a_only = tickets / a - count_ab;
    long long count_b_only = tickets / b - count_ab;

    // Index for iterating through the sorted prices
    int current_p_idx = 0;

    // Apply the highest bonus (x+y) to the most expensive tickets
    for (int i = 0; i < count_ab && current_p_idx < p.size(); ++i) {
        totalProfit += (1LL * p[current_p_idx++] * (x + y) / 100);
    }

    // Apply the next highest bonus (x)
    for (int i = 0; i < count_a_only && current_p_idx < p.size(); ++i) {
        totalProfit += (1LL * p[current_p_idx++] * x / 100);
    }

    // Apply the last bonus (y)
    for (int i = 0; i < count_b_only && current_p_idx < p.size(); ++i) {
        totalProfit += (1LL * p[current_p_idx++] * y / 100);
    }
    
    return totalProfit >= k;
}

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    
    int x, a, y, b;
    cin >> x >> a >> y >> b;
    long long k;
    cin >> k;

    // Sort ticket prices in descending order for optimal profit
    sort(p.rbegin(), p.rend());

    // Binary search on the number of tickets
    int low = 1, high = n, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossibleToSellWithProfitK(mid, a, b, x, y, k, p)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}