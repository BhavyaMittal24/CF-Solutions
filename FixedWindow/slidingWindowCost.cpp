#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<long long> arr(n);
    vector<int> medians;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    ordered_set<pair<long long, int>> st;
    long long current_sum = 0;

    for (int i = 0; i < n; i++) {
        st.insert({arr[i], i});

        if (i >= k) {
            st.erase({arr[i - k], i - k});
        }
        
        if (i >= k - 1) {
            long long median = st.find_by_order(k / 2)->first;
            medians.push_back(median);
        }
    }

    
    cout << endl;
    return 0;
}