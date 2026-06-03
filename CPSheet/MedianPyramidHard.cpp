#include<bits/stdc++.h>
using namespace std;

bool check(int V, const vector<int>& a) {
    int n = a.size();
    int center = n; // 1-based center index is n (since size is 2n-1)
    int min_dist = 2e9;
    int winning_value = -1;

    // Look for adjacent pairs
    for (int i = 0; i < 2 * n - 2; i++) {
        // Convert to binary 0 or 1 based on V
        int curr_bit = (a[i] >= V) ? 1 : 0;
        int next_bit = (a[i+1] >= V) ? 1 : 0;

        if (curr_bit == next_bit) {
            // Calculate distance of this pair from the center
            // Pair is at indices i and i+1 (0-based)
            int dist = max(abs((i + 1) - center), abs((i + 2) - center));
            
            if (dist < min_dist) {
                min_dist = dist;
                winning_value = curr_bit;
            }
        }
    }

    // Edge case: If no adjacent pairs exist, it alternates.
    // The peak will equal the value of the first element.
    if (winning_value == -1) {
        return a[0] >= V;
    }

    return winning_value == 1;
}

int main(){

    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < 2*n - 1; i ++) cin >> arr[i];

    // bs on answer : check if we can find the final median >=x for some number x 
    // x is the top most final median
    
    // ai >= x : 1
    // ai < x : 0
    // now if all valyes >= x are 1 and < x are 0, we want it know if we can have the final med >= x :
    // the max value for this x will be the answer : 
    /// all values >= x will be 1 : if we can get the final median as 1 iw >= x : we 

    int low = 2;
    int high = 2*n - 2;

    int ans = -1;

    while(low <= high){

        int mid = (low + high)/2;

        if(check(mid, arr)){
            ans = mid;
            low = mid+1;
            // go higher : check for a highe rrange from mid+1 to high
        }
        else {
            high = mid-1;
        }
    }

    cout << ans << "\n";
    return 0;
}