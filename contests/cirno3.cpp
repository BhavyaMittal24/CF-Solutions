#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

// Helper to construct a number from a vector of digits
long long formNumbers(const vector<int> &d) {
    long long ans = 0;
    for (int digit : d) {
        ans = ans * 10 + digit;
    }
    return ans;
}

// Helper to fill the remaining digits of a vector with a specific digit
void padRemaining(vector<int> &num, int count, int padDigit) {
    while (count--) {
        num.push_back(padDigit);
    }
}

void solve() {
    long long a;
    int n;
    cin >> a >> n;
    int d1, d2;
    cin >> d1 >> d2;

    long long original_a = a;
    vector<int> digits;

    // Convert target number to its digits
    if (a == 0) {
        digits.push_back(0);
    } else {
        while (a > 0) {
            digits.push_back(a % 10);
            a /= 10;
        }
        reverse(digits.begin(), digits.end());
    }

    int len = digits.size();
    vector<long long> possibleNumbers;

    // -------------------------------------------------------------
    // FIX 1: Explicitly handle Length Transformations cleanly
    // -------------------------------------------------------------
    // Case A: Length - 1 (Maximize the number using the largest digit)
    if (len > 1) {
        vector<int> shortNum;
        int max_d = max(d1, d2);
        int first_d = (max_d == 0) ? min(d1, d2) : max_d;
        if (first_d != 0 || len - 1 == 1) {
            shortNum.push_back(first_d);
            padRemaining(shortNum, len - 2, max_d);
            possibleNumbers.push_back(formNumbers(shortNum));
        }
    }

    // Case B: Length + 1 (Minimize the number using the smallest digit)
    if (len < 19) {
        vector<int> longNum;
        int min_d = min(d1, d2);
        int first_d = (min_d == 0) ? max(d1, d2) : min_d;
        if (first_d != 0) {
            longNum.push_back(first_d);
            padRemaining(longNum, len, min_d);
            possibleNumbers.push_back(formNumbers(longNum));
        }
    }

    // Also include pure 0 if it's one of your digit choices
    if (d1 == 0 || d2 == 0) {
        possibleNumbers.push_back(0);
    }

    // -------------------------------------------------------------
    // FIX 2: Fixed Prefix Matching Logic
    // -------------------------------------------------------------
    vector<int> matchPrefix;
    bool matchedAll = true;

    for (int i = 0; i < len; i++) {
        int targetDigit = digits[i];

        // 1. If we are at the very first digit, prevent leading zeros
        if (i == 0 && len > 1) {
            // Handle tie/difference considering 0 restrictions
            // We evaluate branching manually right here to avoid local traps
        }

        int diff1 = abs(d1 - targetDigit);
        int diff2 = abs(d2 - targetDigit);

        if (diff1 == diff2) {
            // TIE-BREAKER BUG FIXED:
            // We branch down both valid tracks independently without losing data!
            
            // Track 1: Use d1 right now, then choose the optimal extreme
            vector<int> track1 = matchPrefix;
            if (!(i == 0 && d1 == 0 && len > 1)) { // Guard leading zero
                track1.push_back(d1);
                int pad = (d1 > targetDigit) ? min(d1, d2) : max(d1, d2);
                padRemaining(track1, len - 1 - i, pad);
                possibleNumbers.push_back(formNumbers(track1));
            }

            // Track 2: Use d2 right now, then choose the optimal extreme
            vector<int> track2 = matchPrefix;
            if (!(i == 0 && d2 == 0 && len > 1)) { // Guard leading zero
                track2.push_back(d2);
                int pad = (d2 > targetDigit) ? min(d1, d2) : max(d1, d2);
                padRemaining(track2, len - 1 - i, pad);
                possibleNumbers.push_back(formNumbers(track2));
            }

            matchedAll = false;
            break; // Our paths diverged; stop the prefix tracking loop
        } 
        else if (diff1 < diff2) {
            // d1 is strictly closer than d2 locally
            if (d1 == targetDigit) {
                matchPrefix.push_back(d1); // Keep perfectly matching
            } else {
                // It's a mismatch but d1 is closer. Diverge here.
                vector<int> track = matchPrefix;
                if (!(i == 0 && d1 == 0 && len > 1)) {
                    track.push_back(d1);
                    int pad = (d1 > targetDigit) ? min(d1, d2) : max(d1, d2);
                    padRemaining(track, len - 1 - i, pad);
                    possibleNumbers.push_back(formNumbers(track));
                }
                matchedAll = false;
                break;
            }
        } 
        else {
            // d2 is strictly closer than d1 locally
            if (d2 == targetDigit) {
                matchPrefix.push_back(d2); // Keep perfectly matching
            } else {
                // It's a mismatch but d2 is closer. Diverge here.
                vector<int> track = matchPrefix;
                if (!(i == 0 && d2 == 0 && len > 1)) {
                    track.push_back(d2);
                    int pad = (d2 > targetDigit) ? min(d1, d2) : max(d1, d2);
                    padRemaining(track, len - 1 - i, pad);
                    possibleNumbers.push_back(formNumbers(track));
                }
                matchedAll = false;
                break;
            }
        }
    }

    // If the loop finished and successfully matched every digit of A perfectly
    if (matchedAll) {
        possibleNumbers.push_back(formNumbers(matchPrefix));
    }

    // -------------------------------------------------------------
    // Evaluate Global Closest Difference
    // -------------------------------------------------------------
    long long minDiff = LLONG_MAX;
    for (long long num : possibleNumbers) {
        minDiff = min(minDiff, abs(num - original_a));
    }

    cout << minDiff << "\n";
}

int main() {
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