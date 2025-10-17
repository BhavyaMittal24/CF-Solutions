// h, c, tb   1<=c < h <= 1e6
// tb is the absolute desried temperature maintained which can be between c<= t<= h

// no monotonic nature when doing bs on answer

// f(tdiff) is true when there exists a case when we select 2x or 2x+1 cups such that it is possible to have abs temp diff <= |tdiff|

// 30 15 20

// abs difference tavg - tb
// 10 6  3 2 1
// T T  T  F F

// values of tdiff can be 0 to 1e6

// if possible to have another tdiff` such that  :  t`diff <= tdiff

// h c tb

////   |tavg - tb| <= tdiff

//     t2 <= h + c / 2 <= t1
//    t2 <= hx+cx+h/2x+1 <= t1

#include <bits/stdc++.h>
using namespace std;

// FFFFFTTTTTTTTTTTT

// bool isPossibleToGetAbsoluteTempLessThan(int h, int c, int tb, long double tdiff)
// {

//     long double tmax = tdiff + tb;
//     long double tmin = abs(tdiff - tb);
//     long double tavg = (h + c) / 2;
//     if (abs(tavg - tb) <= tdiff)
//         return true;

//     long double lowerCupLimit = (tmin - h) / (c + h - 2);
//     long double upperCupLimit = (tmax - h) / (c + h - 2);
//     if (upperCupLimit < 1)
//         return false;
//     return true;
// }

bool isPossibleToGetAbsoluteTempLessThan(long double h, long double c, long double tb, long double tdiff) {
    
    // Case 1: Equal number of hot and cold cups (at least 2 cups total)
    long double t_equal_mix = (h + c) / 2.0;
    if (abs(t_equal_mix - tb) <= tdiff) {
        return true;
    }
    
    // Case 2: One more hot cup than cold cups (at least 1 cup total)
    // The average temperature is a monotonic function of x.
    // We check the minimum possible difference from this case.
    
    // Subcase 2a: Only one hot cup (x=0)
    // Total 1 cup. Average temp is h.
    if (abs(h - tb) <= tdiff) {
        return true;
    }
    
    // Subcase 2b: More than one cup, with ratio (x+1):x, where x>=1
    // We find the real-valued x that gives an average temp of tb.
    long double h_ld = h, c_ld = c, tb_ld = tb;
    long double t_avg_x_tb_real = (tb_ld - h_ld) / (h_ld + c_ld - 2.0 * tb_ld);
    
    // Check integer x values around this real x.
    // Since x must be >= 1, we check floor and ceil of x, clamped at 1.
    long long x_cand1 = max(1LL, (long long)floor(t_avg_x_tb_real));
    long long x_cand2 = max(1LL, (long long)ceil(t_avg_x_tb_real));

    // Check t_avg for the first integer candidate x
    long double t_avg_x1 = ((long double)x_cand1 * h_ld + (long double)x_cand1 * c_ld + h_ld) / (2.0 * x_cand1 + 1.0);
    if (abs(t_avg_x1 - tb_ld) <= tdiff) {
        return true;
    }
    
    // Check t_avg for the second integer candidate x
    if (x_cand2 != x_cand1) {
        long double t_avg_x2 = ((long double)x_cand2 * h_ld + (long double)x_cand2 * c_ld + h_ld) / (2.0 * x_cand2 + 1.0);
        if (abs(t_avg_x2 - tb_ld) <= tdiff) {
            return true;
        }
    }
    
    return false;
}

void solve(int h, int c, int tb)
{

    // precision = 25 bits : ss = o(1e6*1e25) 100
    long double low = 0;
    long double high = 1e6;
    long double mid = 0;

    for (int i = 0; i < 150; i++)
    {

        mid = low + (high - low) / 2;
        if (isPossibleToGetAbsoluteTempLessThan(h, c, tb, mid))
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    }

    cout << mid << endl;
}

int main()
{

    int t;
    cin >> t;
    cout << fixed << setprecision(10);
    while (t--)
    {
        int h, c, t;
        cin >> h >> c >> t;
        solve(h, c, t);
    }
    return 0;
}