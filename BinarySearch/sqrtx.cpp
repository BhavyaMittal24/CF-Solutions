#include<bits/stdc++.h>

// INT_MAX is 2^31 - 1 which is 2147483647 1e9

using namespace std;

// We want to have a finite search space.
// x is a non negative integer
// Find the square root of a number x upto 6 correct decimal places or with a relative error of 1e-5
// |Real - output| <= 1e-5

double sqrt(double x){
    double low = 0;
    double high =x;
    double precision = 1e-7; // Precision for the binary search
    double mid = 0;
    double ans = 0;
    // Search space is log2(1e9 + 1e7)= 16*3.5 = 56 ~ 75
    while(low <=high)
    {
        mid = low + (high - low) / 2;
        cout << "low: " << low << " high: " << high << " mid: " << mid << endl;
        if( mid* mid <= x){
            low = mid + precision; // Move to the right half
            ans = mid;
        } else {
            high = mid - precision; // Move to the left half
        }
    }
    return ans;
}
int main(){
    // precision
    // double has a fixed precision of 16 digits;
    double x;
    cin >> x;
    // sqrt function returns the square root of a number
    cout << fixed << setprecision(6); // Set precision to 6 decimal places
    cout << sqrt(x) << endl;
}