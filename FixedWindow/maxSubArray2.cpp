// Maximum  sum of subarray of length >=a and lengh <=b
#include<bits/stdc++.h>
using namespace std;

// a = 2
// b = 5

// prefox[r] - prefox[l-1]  subarray starting at l and ednign at r
// I can fix the left index l and find the maximum prefix sum t r where the subarray ends

//     l    [a     b]         l
// -1  0 1  2  3 4 5  6 7 8 9 10

// l+a = index of the first element of an array that starts at l+1 and has min length a

// l+a : index where the subarray ends at max length a
// l+b : index where the subarray ends at max length b
// starts at l+1

// O based   [-1] :           [1,4]
// meaning   starts at 0      ends at 1,4

// l = -1 to l+a < n l = n-1-a

int main()
{

    int n, a, b;
    cin >> n >> a >> b;
    vector<int> arr(n);

    vector<long long> pre(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (i == 0)
            pre[0] = arr[i];
        else
            pre[i] = pre[i - 1] + arr[i];
    }

    // subarray that starts at l+1 index
    // for a valid subarray that has length >=a and <= b it must have end between l+a and l+b index

    int k = b - a + 1;

    /// stores the maximum value of pre[r] for a window k
    multiset<long long> ms;

    long long sum = 0;

    // initially fill the multiset with k values when l=-1

    for (int r = a - 1; r <= b - 1 && r < n; r++)
    {
        ms.insert(pre[r]);
    }
    sum = *ms.rbegin();

    for (int l = 0; l + a < n; l++)
    {
        if (l + b < n) ms.insert(pre[l + b]);
        ms.erase(ms.find(pre[l + a - 1]));
        sum = max(sum, *ms.rbegin()-pre[l]);
    }
    cout << sum << endl;
    return 0;
}