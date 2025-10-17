// // Sushi

// // DP on probability:

// // expected value

// There are
// N dishes, numbered
// 1,2,…,N. Initially, for each
// i (
// 1≤i≤N), Dish
// i has
// a
// i
// ​
//   (
// 1≤a
// i
// ​
//  ≤3) pieces of sushi on it.

// Taro will perform the following operation repeatedly until all the pieces of sushi are eaten:

// Roll a die that shows the numbers
// 1,2,…,N with equal probabilities, and let
// i be the outcome. If there are some pieces of sushi on Dish
// i, eat one of them; if there is none, do nothing.
// Find the expected number of times the operation is performed before all the pieces of sushi are eaten.

// arr[i] : 1 2 3 2 3 1

// index  : 1 2 3 4 5 6 7 .... N

// x = no of operations performed for eating all kinds of sushi
// E(x)

// E(x) = 1/n * (1+)

// 3
// 1 1 1

// 1/ 3( 1 + 1 + 1)

// expected number of operations to make all plates i : 0

// x = no of operations to make all plates have 0 sushis

// count of plates having 0, cnt having 1, 2, 3 etc...
// dp[c0][c1][c2][c3] = c3/n(1 + dp[c0][c1][c2+1][c3-1]) + c2/n * (1 + dp[c0][c1+1][c2-1][c3]) + c1/n * (dp[c0+1][c1-1][c2][c3]) + c0/n(1+dp[c0][c1][c2][c3])

// c0 = n : then 0;

// dp[n] ... = 0;

// (n - c0)* dp(c0,c1,c2, c3) = c3 + c2 + c1 + c0 c3 * dp(c0,c1,c2+1,c3-1) + c2 * dp(c0,c1+1,c2-1,c3) + c1* dp(c0+1,c1-1,c2,c3);

// c3 = n - (c0+c1+c2);

// (n - c0)* dp(c0,c1,c2) = c3 + c2 + c1 + c0 + c3 * dp(c0,c1,c2+1) + c2 * dp(c0,c1+1,c2-1) + c1* dp(c0+1,c1-1,c2);

// dp[c0][c1][c2] =  (n)/(n-c0) + c3/(n-c0) * dp[c0][c1][c2+1] + c2/(n-c0) * dp[c0][c1+1][c2-1] + c1 * dp[c0+1][c1-1][c2];

#include <bits/stdc++.h>
using namespace std;

double dp[302][302][302];
int main()
{
   int n;
   cin >> n;
   vector<int> plates(n + 1);
   int C0 = 0, C1 = 0, C2 = 0, C3 = 0;
   for (int i = 1; i <= n; i++)
   {
      cin >> plates[i];
      if (plates[i] == 0)
         C0++;
      else if (plates[i] == 1)
         C1++;
      else if (plates[i] == 2)
         C2++;
      else
         C3++;
   }
   // plates are n
   // vector<vector<vector<double>>> dp(n+1,vector<vector<double>> (n+1, vector<double>(n+1,0)));

   // i : cpunt of plates having 0 sushis, j : cnt of plates having 1, k : cnt of plates having 2, ...
   // i : 1 to n

   // i,j,k = i,j,k+1,   i,j+1,k-1,   i+1,j-1,k

   // dp[n][0][0] = 0;

   for (int c3 = 0; c3 <= n; c3++)
   {
      for (int c2 = 0; c2 <= n; c2++)
      {
         for (int c1 = 0; c1 <= n; c1++)
         {
            int c0 = n - (c1 + c2 + c3);
            if (c0 == n)
            {
               dp[c1][c2][c3] = 0;
               continue;
            }
            double E1 = 0;
            double E2 = 0;
            double E3 = 0;
            double p3 = 1.0*c3 / n;
            double p2 = 1.0*c2 / n;
            double p1 = 1.0*c1 / n;

            double ans = 1.0;
            if (c3 > 0)
               E3 = p3 * dp[c1][c2+1][c3-1];
            if (c2 > 0)
               E2 = p2 * dp[c1+1][c2 - 1][c3];
            if (c1 > 0)
               E1 = p1 * dp[c1-1][c2][c3];
            double rem = 1 - 1.0* c0 / n;
            ans = ans * (1 + E1 + E2 + E3);
            dp[c1][c2][c3] = ans / rem;
         }
      }
   }

   cout << fixed << setprecision(10) << dp[C1][C2][C3] << endl;
   return 0;
}
