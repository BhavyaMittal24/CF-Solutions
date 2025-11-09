#include<bits/stdc++.h>
using namespace std;

// Array size is 11, which supports calculating factorial up to 10!
// This assumes the maximum number of '?' (cntQ) is 10.
long long factorial[11];

// Fills the factorial array up to 10!
void setFactorial(){
    factorial[0] = 1;
    // Iterate up to 10 (index 10 is the last element in array of size 11)
    for(int i=1; i < 11; i++){
        // Safety check to prevent array index out of bounds, though size 11 should cover 0..10
        if (i < 11) {
            factorial[i] = (long long)i * factorial[i-1];
        }
    }
}

// Calculates the binomial coefficient C(n, r) = n! / (r! * (n-r)!)
long double choose(int n, int r){
    // Optimization and safety check for C(n,r) = C(n, n-r)
    if (r < 0 || r > n) return 0;
    if (r == 0 || r == n) return 1.0;
    if (r > n / 2) r = n - r;

    // We rely on the pre-calculated factorials
    long double num = factorial[n];
    long double den = factorial[n-r] * factorial[r];
    
    return num / den;
}

int main(){
    // IMPORTANT: Call setFactorial() to initialize the global array
    setFactorial();
    
    // Use fixed precision for required output format
    cout << fixed << setprecision(8);

    string s1;
    string s2;

    if (!(cin >> s1 >> s2)) return 0;

    // Initial check (can be skipped since moves are defined by position, but good practice)
    if(s1.length() != s2.length()) {
        cout << 0.0 << endl;
        return 0;
    }

    // --- 1. Calculate Target Position from s1 ---
    int cntPlusS1 = 0;
    int cntMinusS1 = 0;
    
    for(char c : s1){
        if(c == '+') cntPlusS1++;
        else if(c == '-') cntMinusS1++;
    }
    int targetPosition = cntPlusS1 - cntMinusS1;

    // --- 2. Calculate Current Known Position and Unknown Moves from s2 ---
    int cntPlusS2 = 0;
    int cntMinusS2 = 0; // Correctly track '-' moves in s2
    int cntQ = 0;       // Number of '?' (random moves)

    for(char c : s2){
        if(c == '+') cntPlusS2++;
        // FIX: Increment cntMinusS2 for '-'
        else if(c == '-') cntMinusS2++;
        else cntQ++;
    }
    int currentKnownPosition = cntPlusS2 - cntMinusS2;

    // --- 3. Determine Required Net Change ---
    int requiredNetChange = targetPosition - currentKnownPosition;

    // If there are no '?' moves, the positions must match exactly
    if(cntQ == 0){
        cout << (requiredNetChange == 0 ? 1.0 : 0.0) << endl;
        return 0;
    }

    // --- 4. Feasibility Check and Probability Calculation ---
    
    // Feasibility Check 1: The required net change (R) cannot exceed the total available moves (cntQ).
    if (abs(requiredNetChange) > cntQ) {
        cout << 0.0 << endl;
        return 0;
    }

    // Feasibility Check 2: The required net change (R) and the number of unknown moves (cntQ) 
    // must have the same parity. (i.e., R + cntQ must be even)
    if ((requiredNetChange + cntQ) % 2 != 0) {
        cout << 0.0 << endl;
        return 0;
    }

    // The required number of '+' moves (k) from '?'s is calculated by:
    // k - (cntQ - k) = R  => 2k - cntQ = R  => k = (R + cntQ) / 2
    int requiredPlusMoves = (requiredNetChange + cntQ) / 2;
    // The number of required '-' moves is automatically cntQ - k.

    // The number of successful outcomes is the number of ways to choose 'requiredPlusMoves' out of 'cntQ' slots.
    long double combinations = choose(cntQ, requiredPlusMoves);
    
    // The total possible outcomes is 2^(cntQ)
    long double totalOutcomes = pow(2.0, cntQ);

    long double probability = combinations / totalOutcomes;
    cout << probability << endl;

    return 0;
}
