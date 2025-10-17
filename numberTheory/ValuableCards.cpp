// Valuable cards

// 8 6
// 4 3 4 3 4 3 4 3

// x = 6

// find the min no of segments such that each segment is bad where no subsequence exists in the segment which has product as x

// // basically good subarray/segment has all the factors of x

// factors
// currentFactorsPossible

// // no of factors is

#include <bits/stdc++.h>
using namespace std;
void solve()
{
        int n, x;
        cin >> n >> x;
        // n = 2*1e5
        // factors of x = cbrt(x)
        // x <= 1e5
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        set<int> factors;

        for (int d = 1; d * d <= x; d++)
        {
            if (x % d == 0)
            {
                factors.insert(d);
                factors.insert(x / d);
            }
        }
        // x = 10
        // 1 2 5

        // factors = {1,2,5,10}
        // 2 ->  1
        //  2/2 Yes
        //  5/2
        //  10/2
        // currentFactorsPossible = {1}

        //
        set<int> possibleFactors;
        possibleFactors.insert(1);
        long long segments = 1;
        for (int i = 0; i < n; i++)
        {

            if (x % a[i] != 0) continue;
            set<int> newFactorsPossible;
            for (auto factor : factors)
            {
                // a[i] can make some factor p1
                // a[i] * alrefdy present factor = p1

                if ( factor % a[i] == 0 && possibleFactors.count(factor / a[i]))
                {
                    newFactorsPossible.insert(factor);
                }
            }
             if (newFactorsPossible.count(x))
            {
                segments++;
                possibleFactors.clear();
                possibleFactors.insert(1);
                possibleFactors.insert(a[i]);
            }
            else
            {
                for (auto it : newFactorsPossible)
                    possibleFactors.insert(it);
            }
           
        }
        cout << segments << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}