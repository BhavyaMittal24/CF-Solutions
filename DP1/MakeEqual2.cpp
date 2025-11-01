#include<bits/stdc++.h>
using namespace std;

// Maximum B_i value in the input (10^3)
const int B_LIMIT = 1000;
const int INF = 1e9;

// Maximum total operations needed: N_max * max_moves(B_max) = 1000 * 14 = 14000. 
// We use a safe cap for the steps dimension in the DP table.
const int MAX_TOTAL_STEPS = 14005; 

// Array to store the minimum number of moves required to reach value 'v' starting from 1.
// Size is B_LIMIT + 1.
int min_moves[B_LIMIT + 1]; 

// --- Subproblem Pre-calculation using Breadth-First Search (BFS) ---
// Calculates the minimum moves required to reach any number up to B_LIMIT 
// starting from 1, using the operation: curr -> curr + floor(curr / x).
void preCalculateMinMoves() {
    // We only need to run this once for all test cases as B_LIMIT is constant.
    
    // Initialize moves array
    fill(min_moves, min_moves + B_LIMIT + 1, INF);
    
    // Base case: reaching 1 requires 0 moves.
    min_moves[1] = 0;
    
    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        // If we exceed the maximum B value, we stop exploring this path.
        if (curr >= B_LIMIT) continue;

        // Iterate through all possible operation choices for x.
        // We only need to check x up to curr, since x > curr yields floor(curr/x)=0, which is useless.
        for (int x = 1; x <= curr; x++) {
            // Note: Integer division is crucial here: curr / x
            int next = curr + (curr / x);
            
            // Check boundary and ensure we found a shorter path.
            if (next <= B_LIMIT && min_moves[curr] + 1 < min_moves[next]) {
                min_moves[next] = min_moves[curr] + 1;
                q.push(next);
            }
        }
    }
}

void solve(){
    int n;
    long long k;
    if (!(cin >> n >> k)) return;

    vector<int> b(n);
    vector<long long> c(n);
    
    for(int i=0;i<n;i++){
        cin >> b[i];
    }

    for(int i=0;i<n;i++){
        cin >> c[i];
    }
    
    // We cap the DP table size at the maximum useful steps (14005)
    int max_steps = min((long long)k, (long long)MAX_TOTAL_STEPS);

    // dp[steps] is the maximum cost using a subset of items with at most 'steps' operations.
    // Using 1D DP for space optimization.
    vector<long long> dp(max_steps + 1, 0);

    for(int i = 0; i < n; i++){ // Iterate over items
        
        // 1. Get the required moves for b[i] from the pre-calculated table.
        long long moves = INF;
        if (b[i] <= B_LIMIT) {
             moves = min_moves[b[i]];
        }
        
        // 2. Perform 0/1 Knapsack transition (Iterate steps backwards)
        if (moves != INF) {
            for(int steps = max_steps; steps >= moves; steps--){
                // Option: TAKE item i
                dp[steps] = max(dp[steps], c[i] + dp[steps - moves]);
            }
        }
    }
    
    // The final answer is dp[max_steps]
    cout << dp[max_steps] << endl;
}

int main(){
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; 
    // Run pre-calculation once before reading test cases to ensure efficiency
    preCalculateMinMoves();

    if (!(cin >> t)) return 0;
    
    while(t--){
        solve();
    }
    
    return 0;
}
