// Balancing heaps
#include <bits/stdc++.h>
using namespace std;

// go from heap number 3 to n in this order
// 1 2 3 4
// 1+2 2+1 0
// for i., transfer at max i/3 to i-1 and 2i/3 to the i-2th heap

// potential candidate answers = 1 to 1e9 [hi]
// x = number of stones in all the heaps after the operation
// f(x) =  T if the minimum number of stones in all heaps after operation >=x

// number of stones in each heap after operation should be atleast >=x
//.. 1 2 3 … 6 …. .. 1e9
//      l       l  h  h  h      h
//   T T T   T  F FFFFFFFF

// ways to make the stones in all the heaps maximum
// 0 1 2    i-2 i-1 i          <-n-1
//                    i%3(0,1,2)

// x is the min number of stones in all heaps
// T if all heaps have atleast x stones

//   heaps
// 1 2 3 4 5 6

/// 1 2 10 100

// x- 7

// arr[i] + y >=x
//  d/3>= x - arr[i]
//  d >= 3(X-arr[i])
// if( d
// 1+2*3, 2+3+
// x = 3
//    1+2, 2+1, 3

// x is the minimum number of stones in all the heaps

//   0<= 3d <= hi
// let ai be the number of stones in heap it has + what it got from transdfer : ai =  hi + t
//                ai
// 0 1 2 3 .....i........ n-1

//              we can transfer to left : min ( ai-x, hi)
// if (ai - x > hi) i cant transfer, because i am moving from left to right, i dont have so many stones, i will recieve the extra t stones later on
//     ai - x < hi, then i would have to transfert ai-x, cant as this will make x stones remaining

bool isPossible(vector<long long> &heaps, int mid)
{
    // we want to have the maximum stones left after operation.
    vector<long long> a = heaps;
    int n = heaps.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] < mid)
            return false;
        long long d = min(a[i] - mid, heaps[i]) / 3;
        if (i >= 2)
        {
            a[i - 1] += d;
            a[i - 2] += 2 * d;
        }
    }
    return true;
}
// l h
// T F FFFTTFFFFFFF
void solve()
{
    int n;
    cin >> n;
    vector<long long> heaps(n);
    for (int i = 0; i < n; i++)
    {
        cin >> heaps[i];
    }
    // 1 <=heaps [i] <= 1e9
    int low = 0;
    int high = 1e9;
    int mid = 0;
    int ans = -1;

    while (low <= high)
    {
        mid = (low + high) / 2;
        //cout << "low : " << low << " high : " << high << " mid : " << mid << endl;
        if (isPossible(heaps, mid))
        {
            ans = mid;
            low = mid+1;
        }
        else high = mid - 1;
    }
    cout << ans << endl;
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}