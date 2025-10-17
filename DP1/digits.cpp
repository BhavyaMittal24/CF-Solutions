// 5 -> 6 -> 7 -> 8 -> 9 > 10 -> 21

// 88 2

// 88 -> 9 9 - > 10 10

// number n

// m operations : length of final number n`

// string of digits : n
//                                                ith number
//  n -> - … after I operations :i-th number  ->  d1d2...dk

// 88 -> 99 - > 1010 9898 109109  21101010

// 0011  ->  8899 -> 991010 -> 10102121  99
    //trhrth
// m is 1e5
// n  <= 1e9 : 10 digits max : but after m operations it can be v big, but then no of digits is log10(n)

// // np of digits of n after m operations is ~ rough approx : 100 : n would be around log10(10^100) : which is a safe bet

// // No : I cant store : as no of digits are around % 1e9+7   : n can go log(10 ^ 10^9)

// // add 1 to each bit and replace it there only

// // cnt of digits in new number after 1 operation
// // 88 : all numbers <9 : cnt = cnt + 0;
// // for each number = 9 : cnt = cnt +1 ; // cnt inc by 1 for a number = 9
// // Store the count for each digit [0,9] : cnt0, cnt1 ……….. cnt9

// //

//       i-1th operation                  ->   i operations
//          99                                    1010

//    state : cnt of each digit in the number from i-1 operations so far and the current operation number

//   operations : 0 to m

//    base case : if(i == 0) return log10(n);

//    dp[i][c0][c1][c2][c3][c4]c5[c6][c7]c8[c9] = dp[i-1] + c9 + dp[c0][c1][..]

                                                // prevDigits + extradigits
                                                // extra digits = cnt9 : as each 9 will give rise to an extra digit : 1 and 0 for each 9

// dp[i][vector of cnt of each digit] = no of digits after i operations

// dp[i][c0][c1]...[c9] = dp[i-1][][] + cnt9
//   completely new c0, c1 …
//   if(c0 > 0) {
//      c0` = c0-1
//      c1` = c1+1;
//   }
//   if(c1 > 0) {

//   }

//   .

//   if(c9 > 0){

//   }

#include <bits/stdc++.h>
using namespace std;

long long n;
////
const long long mod = 1e9 + 7;

// // 0, n -> 1, n1  -> 2, n2 -> 3, n3 -> 4, n4  ... -> m, nm
// long long numberOfDigits(int stepsLeft, vector<long long> countForDigit)
// {
// }

void solve()
{

    cin >> n;
    int m;
    cin >> m;
    vector<long long> countForDigit(10, 0);
    long long temp = n;
    long long prevDigits = 0;
    while (temp > 0)
    {
        int digit = temp % 10;
        countForDigit[digit]++;
        temp = temp / 10;
        prevDigits++;
    }
    // cout << prevDigits << " ";
    vector<long long> newCountForDigit(10, 0);
    long long extraDigits = 0;
    long long sum = 0;
    for (int stepsLeft = 1; stepsLeft <= m; stepsLeft++)
    {
        extraDigits = 0;
        sum = 0;
        for (int i = 0; i <= 9; i++)
        {

            if (countForDigit[i] > 0 && i != 9)
            {
                newCountForDigit[i + 1] = countForDigit[i];
                // sum = (sum + newCountForDigit[i+1] ) % mod;
            }
            if (i == 9 && countForDigit[9] > 0)
            {
                newCountForDigit[1] = (countForDigit[9] + newCountForDigit[1]) % mod;
                newCountForDigit[0] = (countForDigit[9] + newCountForDigit[0]) % mod;
                extraDigits += (extraDigits + countForDigit[9]) % mod;
            }
        }
        sum = (prevDigits + extraDigits) % mod;
        countForDigit = newCountForDigit;
        newCountForDigit = vector<long long>(10, 0);
        prevDigits = sum;
    }

    cout << sum % mod << endl;
    return;
    // 10349
}


int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
