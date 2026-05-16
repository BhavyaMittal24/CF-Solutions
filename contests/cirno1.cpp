#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

long long target;
long long minDiff;
int d1, d2;
string targetStr;

void solveTrack(string &curr) {
    if (curr.length() > 0) {
        long long val = stoll(curr);
        minDiff = min(minDiff, abs(val - target));
    }

    if (curr.length() >= targetStr.length() + 1) return;

   
    if (curr.length() > 0) {
        long long val = stoll(curr);
        if (curr.length() == targetStr.length() && abs(val - target) > minDiff) {
        }
    }

    // Push d1
    if (!(curr == "0")) {
        curr.push_back('0' + d1);
        solveTrack(curr);
        curr.pop_back();
    }

    // Push d2
    if (d1 != d2 && !(curr == "0")) {
        curr.push_back('0' + d2);
        solveTrack(curr);
        curr.pop_back();
    }
}

void solve() {
    int n;
    cin >> target >> n;
    cin >> d1 >> d2;

    targetStr = to_string(target);
    minDiff = 2e18; 
    
    vector<long long> candidates;
    if (d1 == 0 || d2 == 0) candidates.push_back(0);

    int len = targetStr.length();
    
    
    auto fillRest = [&](string prefix, char choice, int restLen, char fillChar) {
        prefix.push_back(choice);
        while(restLen--) prefix.push_back(fillChar);
        return stoll(prefix);
    };

    if (len > 1) {
        string shortCandidate(len - 1, '0' + d2);
        candidates.push_back(stoll(shortCandidate));
    }
    
   
    char startChar = (d1 == 0) ? '0' + d2 : '0' + d1;
    string longCandidate(len + 1, (d1 == 0 && startChar == '0' + d2) ? '0' + d1 : '0' + d1);
    string longCand = "";
    longCand.push_back(startChar);
    for(int i=0; i<len; i++) longCand.push_back('0' + d1);
    candidates.push_back(stoll(longCand));

    
    string currentPrefix = "";
    for (int i = 0; i < len; i++) {
        candidates.push_back(fillRest(currentPrefix, '0' + d1, len - 1 - i, '0' + d2)); // fill rest with max
        candidates.push_back(fillRest(currentPrefix, '0' + d1, len - 1 - i, '0' + d1)); // fill rest with min
        
        candidates.push_back(fillRest(currentPrefix, '0' + d2, len - 1 - i, '0' + d2)); 
        candidates.push_back(fillRest(currentPrefix, '0' + d2, len - 1 - i, '0' + d1));

        int targetDigit = targetStr[i] - '0';
        if (targetDigit == d1) {
            currentPrefix.push_back('0' + d1);
        } else if (targetDigit == d2) {
            currentPrefix.push_back('0' + d2);
        } else {
            break;
        }
    }
    if(currentPrefix.length() == len) {
        candidates.push_back(stoll(currentPrefix));
    }

    long long ans = 2e18;
    for (long long c : candidates) {
        ans = min(ans, abs(c - target));
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}