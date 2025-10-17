// You are very close to the correct DP formulation for this expected value problem\! The DP state and the idea of calculating the expected value iteratively are correct. However, you've hit a common mistake in setting the **boundaries for your loops**, which leads to accessing out-of-bounds indices and potentially incorrect results (like 0 if the base case isn't correctly defined relative to the iteration order).

// The core of the issue is that your loops run up to $n$ for $c_1$ and $c_2$, even when $c_0+c_1+c_2 > n$. Additionally, your iteration for $c_3$ is implicit and relies on the constraint.

// Here is a breakdown of the issue and the corrected implementation logic.

// ## 1\. The DP State and Recurrence

// Your DP state and the derived recurrence are fundamentally correct for this problem:

//   * **State:** $\text{dp}[c_1][c_2][c_3]$ is the expected number of additional operations required to finish, given there are $c_1$ plates with 1 sushi, $c_2$ plates with 2 sushi, and $c_3$ plates with 3 sushi. (You correctly derived that $c_0 = n - c_1 - c_2 - c_3$ is the number of empty plates, so it's determined by the other three counts, simplifying the state to $\text{dp}[c_1][c_2][c_3]$. You used $c_0, c_1, c_2$ in your array, which is also fine, but you need to be careful with the total sum).
//   * **Target:** We want $\text{dp}[C_1][C_2][C_3]$ based on the initial counts.
//   * **Base Case:** $\text{dp}[0][0][0] = 0$.

// Let $S = c_1 + 2c_2 + 3c_3$ be the total number of remaining sushi pieces. This is equivalent to $n-c_0$, the number of non-empty plates.

// The full recurrence (before simplification) is:
// $$\text{dp} = 1 + \frac{c_3}{n}\text{dp}(c_1, c_2+1, c_3-1) + \frac{c_2}{n}\text{dp}(c_1+1, c_2-1, c_3) + \frac{c_1}{n}\text{dp}(c_1-1, c_2, c_3) + \frac{c_0}{n}\text{dp}$$

// Rearranging to solve for $\text{dp}$:
// $$\text{dp}\left(1 - \frac{c_0}{n}\right) = 1 + \frac{c_3}{n}\text{dp}(\dots) + \frac{c_2}{n}\text{dp}(\dots) + \frac{c_1}{n}\text{dp}(\dots)$$

// Since $1 - \frac{c_0}{n} = \frac{n-c_0}{n} = \frac{c_1+c_2+c_3}{n} = \frac{S}{n}$:
// $$\text{dp}[c_1][c_2][c_3] = \frac{n}{S} + \frac{c_3}{S}\text{dp}(c_1, c_2+1, c_3-1) + \frac{c_2}{S}\text{dp}(c_1+1, c_2-1, c_3) + \frac{c_1}{S}\text{dp}(c_1-1, c_2, c_3)$$

// Your implementation uses $c_0, c_1, c_2$ as state variables and $c_3 = n - c_0 - c_1 - c_2$. The variable $S$ is $\mathbf{n - c_0}$. This is mathematically correct.

// ## 2\. The Implementation Errors

// The main issues are in the loop bounds and the definition of the state variables:

// ### A. Incorrect Loop Bounds and Total Constraint

// In your code, the loops are:

// ```cpp
// for(int c0=n; c0>= 0; c0--) {
//     for(int c1 = n;c1 >=0 ; c1 --){
//         for(int c2 = n;c2 >= 0; c2 --){
//              // ... c3 = n - (c0+c1+c2);
// ```

// This iterates over many impossible states where $c_0 + c_1 + c_2$ is much greater than $n$.

// **Correction:** The number of sushi pieces $c_1, c_2, c_3$ must sum up to at most $n$.

// ### B. Indexing and State Variable Order

// Your DP array is declared as `dp[302][302][302]`. Given the problem constraint $N \le 300$, this must correspond to the counts $c_1, c_2, c_3$, not $c_0, c_1, c_2$.

// Since $c_3$ is determined by $c_0, c_1, c_2$, the dimensions should represent $c_0, c_1, c_2$ **OR** $c_1, c_2, c_3$. Sticking to the common representation: **$\text{dp}[c_1][c_2][c_3]$**.

// Since $c_1+c_2+c_3 \le n$, the maximum value for $c_1, c_2,$ and $c_3$ is $n$. The maximum index for $c_1, c_2, c_3$ is $n$, so the array size should be $[n+1][n+1][n+1]$.

// Let's stick to the state $\text{dp}[c_1][c_2][c_3]$. We iterate backward from the highest counts:

// ```cpp
// // Correct state: dp[c1][c2][c3]
// // We must iterate backwards to ensure dp[future_state] is already calculated.
// // A move from (c1, c2, c3) always leads to a state with one less total sushi, 
// // so iterating from high to low total sushi is correct.
// for(int c3 = n; c3 >= 0; c3--) {
//     for(int c2 = n; c2 >= 0; c2--) {
//         for(int c1 = n; c1 >= 0; c1--) {
//             int c0 = n - (c1 + c2 + c3);
            
//             // 1. Constraint check: Total plates must be <= n
//             if (c0 < 0) continue; 
            
//             // 2. Base Case Check: Finished when c1=c2=c3=0 (c0=n)
//             if (c1 == 0 && c2 == 0 && c3 == 0) continue; // dp[0][0][0] = 0 (implicitly)
            
//             // 3. Skip if no sushi remaining
//             if (c1 + c2 + c3 == 0) continue; 
            
//             double S = (double)c1 + c2 + c3;
//             double expected = n / S; // n / (n - c0) is the first term
            
//             // Term 1: Roll 3-sushi plate -> (c3-1, c2+1, c1)
//             if (c3 > 0) {
//                 expected += (c3 / S) * dp[c1][c2 + 1][c3 - 1];
//             }
//             // Term 2: Roll 2-sushi plate -> (c3, c2-1, c1+1)
//             if (c2 > 0) {
//                 expected += (c2 / S) * dp[c1 + 1][c2 - 1][c3];
//             }
//             // Term 3: Roll 1-sushi plate -> (c3, c2, c1-1)
//             if (c1 > 0) {
//                 expected += (c1 / S) * dp[c1 - 1][c2][c3];
//             }
            
//             dp[c1][c2][c3] = expected;
//         }
//     }
// }
// ```

// ## Final Corrected Code

// Here is the corrected and clean implementation.

// ```cpp
#include<bits/stdc++.h>
using namespace std;

// dp[c1][c2][c3]: Expected number of operations needed, given c1 plates have 1 sushi, 
// c2 plates have 2 sushi, and c3 plates have 3 sushi.
double dp[301][301][301];

void solve() {
    int n;
    cin >> n;
    
    int C1 = 0, C2 = 0, C3 = 0;
    int a_i;
    for(int i = 0; i < n; i++) {
        cin >> a_i;
        if(a_i == 1) C1++;
        else if(a_i == 2) C2++;
        else if(a_i == 3) C3++;
    }

    // Initialize DP array (implicit base case dp[0][0][0] = 0)
    // The dimensions are [c1+1][c2+1][c3+1], max index is n, so size n+1
    // We only need to check up to the maximum possible counts, which is n.
    
    // Iterate backwards so that future states (fewer total sushi) are calculated first.
    for(int c3 = n; c3 >= 0; c3--) {
        for(int c2 = n; c2 >= 0; c2--) {
            for(int c1 = n; c1 >= 0; c1--) {
                
                int total_sushi_plates = c1 + c2 + c3;
                
                // Skip impossible states and the final state
                if (total_sushi_plates == 0) continue; 
                if (total_sushi_plates > n) continue; 

                // S is the number of non-empty plates, which is n-c0
                double S = (double)total_sushi_plates;
                
                // E = n/S + (Prob_3 * E_3) + (Prob_2 * E_2) + (Prob_1 * E_1)
                
                double expected = (double)n / S; 
                
                // Transition 1: Roll 3-sushi plate (Probability c3/n * n/S = c3/S)
                // New state: c3-1, c2+1, c1
                if (c3 > 0) {
                    expected += (c3 / S) * dp[c1][c2 + 1][c3 - 1];
                }
                
                // Transition 2: Roll 2-sushi plate (Probability c2/S)
                // New state: c3, c2-1, c1+1
                if (c2 > 0) {
                    expected += (c2 / S) * dp[c1 + 1][c2 - 1][c3];
                }
                
                // Transition 3: Roll 1-sushi plate (Probability c1/S)
                // New state: c3, c2, c1-1
                if (c1 > 0) {
                    // Check bounds for c1-1. c1 is guaranteed >= 1 here.
                    expected += (c1 / S) * dp[c1 - 1][c2][c3];
                }
                
                dp[c1][c2][c3] = expected;
            }
        }
    }

    cout << fixed << setprecision(10) << dp[C1][C2][C3] << endl;
}

int main()
{
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Since the problem only asks for one test case, call solve directly.
    // If it were multiple test cases, you'd need to reinitialize the DP array inside solve or main loop.
    solve();
    
    return 0;
}
