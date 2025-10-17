#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std;

void solve(){
    int n;
    if (!(cin >> n)) return;
    
    string s;
    cin >> s;

    // 1. Calculate the total counts
    int total_a = 0;
    int total_b = 0;
    for(char c : s){
        if(c == 'a') total_a++;
        else total_b++;
    }

    int diff_abs = abs(total_a - total_b);
    
    if(diff_abs == 0){
        cout << 0 << "\n";
        return;
    }
    
    // The required difference in the removed substring (A_sub - B_sub)
    const int TARGET_DIFF = diff_abs; 
    
    int min_len = n + 1; 
    
    int left = 0;
    int current_a = 0;
    int current_b = 0;

    // We track the actual signed difference
    int target_signed_diff = total_a - total_b; // e.g., 3 for aabaa

    for(int right = 0; right < n; right++){
        if(s[right] == 'a') current_a++;
        else current_b++;
        
        int current_signed_diff = current_a - current_b;
        
        // Shrinking Loop: We only want to shrink if we have passed the target difference.
        // Shrink if the current difference has the same sign as the target and is >= |target|
        // OR if the current difference is on the wrong side (e.g., negative when target is positive)
        
        // If the current window's difference is already >= the target's magnitude
        while(abs(current_signed_diff) >= TARGET_DIFF && left <= right){
            
            // CRITICAL CHECK: Check for EXACT match AND non-full removal
            if(current_signed_diff == target_signed_diff){
                 // The check for < n ensures the remaining string is non-empty.
                 if ((right - left + 1) < n) {
                    min_len = min(min_len, right - left + 1);
                 }
            }
            
            // Shrink the window
            if(s[left] == 'a') current_a--;
            else current_b--;
            
            left++;
            
            current_signed_diff = current_a - current_b;
        }
    }

    // 4. Final Output
    if(min_len == n + 1) {
        cout << -1 << "\n"; 
    } else {
        cout << min_len << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while(t--){
        solve();
    }
    
    return 0;
}