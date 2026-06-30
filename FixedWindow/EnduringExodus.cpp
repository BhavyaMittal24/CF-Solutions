#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;
    
    string s;
    cin >> s;

    // Store 1-based indices of all '0's
    vector<int> zero;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            zero.push_back(i + 1);
        }
    }

    // We need a window containing exactly (k + 1) zeros
    k++; 

    if (zero.size() < k) {
        cout << 0 << "\n";
        return 0;
    }

    int minDiff = n; 

    int med = 0;

    for (int i = 0; i < zero.size(); i++) {
        if (i >= k - 1) {
            int left = i - k + 1;
            int right = i;
            
            while(med <= zero.size() - 2 && max(zero[right] - zero[med], zero[med] - zero[left]) > max(zero[right] - zero[med+1], zero[med+1] - zero[left])){
                med++;
            }

            minDiff = min(minDiff, max(zero[med] - zero[left], zero[right]- zero[med]));
        }
    }

    cout << minDiff << "\n";
    return 0;
}