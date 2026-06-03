// #include<bits/stdc++.h>
// using namespace std;

// bool checkPlace(int height, int W, multiset<int> widths){

//     // msb for each numebr is there : you can find if that bit is present in W or not 

//     // widths is all the memebers you need to place in the box

//     while(height-- && widths.size() > 0){

//         int maxWidth = W;
//         vector<int> removeW;
//         auto it = widths.rbegin();
//         while( it != widths.rend()){

//             int width = *it;
//             if( maxWidth >= width){
//                 maxWidth = maxWidth - width;
//                 removeW.push_back(width);
//             }
//             else if(maxWidth == 0) break;
//             it++;
//         }

//         for(auto w : removeW){
//             widths.erase(widths.find(w));
//         }
//     }

//     if(widths.size() > 0) return false;

//     return true;
// }


// void solve(){
//     int n;
//     int W;
//     cin >> n >> W;
//     long long area = 0;

//     multiset<int> widths;
//     for(int i = 0; i < n; i ++){
//         int x;
//         cin >> x;
//         area += x;
//         widths.insert(x);
//     }

//     int high = n;
//     int low = 1;

//     int ans = -1;

//     while(low <= high){

//         int mid = (high + low)/2;

//         if(checkPlace(mid, W, widths)){
//             ans = mid;
//             high = mid-1;
//         } 

//         else {
//             low = mid+1;
//         }
//     }
//     cout << ans << "\n";

// }
// int main(){

//     ios_base::sync_with_stdio(false);
//     // cin.tie(NULL);
//     int t;
//     cin >>t;

//     while(t--){
//         solve();
//     }

//     return 0;
// }

// /*

// 1001
// 34 944
// 4 256 512 16 1 16 1 64 4 16 64 256 128 4 64 128 16 2 512 512 1 512 128 512 8 4 8 2 32 2 1 32 128 4
// 97 590
// 4 2 32 1 1 1 16 256 32 32 2 8 512 1 16 64 64 512 8 128 8 64 4 2 64 256 16 32 16 128 16 16 32 512 128 2 1 256 128 4 4 1 64 1 4 128 128 2 4 128 512 256 4 2 64 16 2 128 128 512 32 32 8 64 128 16 8 4 16 8 64 1 128 64 128 256 4 512 8 1 1 64 16 64 8 1 128 8 2 64 8 512 256 8 64 64 1
// 63 250
// 4 32 4 4 32 2 8 64 4 16 16 16 1 128 16 32 2 16 1 64 16 32 2 2 16 16 16 16 128 2 1 1 1 1 8 8 64 1 64 64 ...
// */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Returns true if all rectangles can fit within height 'h'
bool check(long long h, const vector<long long>& c, long long W) {
    // Make a copy of our requirement array to modify during the check
    vector<long long> req = c; 
    long long leftovers_passed_down = 0;

    // Iterate from the largest width (2^19) down to the smallest (2^0)
    for (int i = 19; i >= 0; i--) {
        long long width = (1 << i);

        // Base capacity provided by the box at this height for width 2^i
        long long available_slots = h * (W / width);

        // Add the slots inherited from the larger leftovers split in half
        available_slots += leftovers_passed_down;

        // If we don't have enough slots to satisfy the rectangles of this size
        if (available_slots < req[i]) {
            return false;
        }

        // Calculate how many slots are left over, and multiply by 2 
        // because 1 slot of size 2^i splits into 2 slots of size 2^(i-1)
        leftovers_passed_down = (available_slots - req[i]) * 2;
    }

    return true;
}

void solve() {
    int n;
    long long W;
    cin >> n >> W;

    // c[i] stores the number of rectangles of width 2^i
    vector<long long> c(20, 0);
    for (int i = 0; i < n; i++) {
        int w;
        cin >> w;
        // __builtin_ctz(w) finds the power of 2 (e.g., 4 -> 2, 8 -> 3)
        int power = __builtin_ctz(w); 
        c[power]++;
    }

    // Binary search boundaries for height
    long long low = 1;
    long long high = n; // Worst case: each rectangle takes its own row
    long long ans = n;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (check(mid, c, W)) {
            ans = mid;        // 'mid' works, try to find a smaller height
            high = mid - 1;
        } else {
            low = mid + 1;    // 'mid' is too short, we need more height
        }
    }

    cout << ans << "\n";
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