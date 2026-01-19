// a ; a1, a2, ... an

// form an array b which is the subsequence of array a where
// contrast value is same

// max size of array b = n, same as array a
// min size of array b can be 1 when the contrast value is 0 for the array a : 1,1,1,1
// contrast value of [x] = 0
// min size other than this can be 2 when the b = [b1, b2] where b1 - b2 = contrast value of a

// contrast value of a would be in long long

// min possible size of b ?

// brute force : seach for all possible sizes and check : all subarrays min sizes from 1 to n

// to check for all subarrays of size k : it would take n*n complecity

// use binary search on answer : for a subarray of size k : is it possible to have a contrast value in that wondow : use slidig window
// [ a1 a2 a3 a4 a5]  : k = 3

// + (a4 - a3) - ( a2-a1)

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // check for the min possuble size for the array b

    if (a.size() == 1)
    {
        cout << "1\n";
        return;
    }

    vector<int> ans;

    ans.push_back(a[0]);
    ans.push_back(a[1]);

    int currSize = 0;
    for (int i = 2; i < n; i++)
    {

        int currSize = ans.size();
        int first = ans[currSize - 2];
        int second = ans[currSize - 1];

        int x = first - second;
        int y = second - a[i];

        if (x > 0)
        {
            if (y > 0)
                ans[currSize - 1] = a[i];
            else if (y < 0)
                ans.push_back(a[i]);
        }
        else
        {
            if (y < 0)
                ans[currSize - 1] = a[i];
            else if (y > 0)
                ans.push_back(a[i]);
        }
    }

    int finalSize = ans.size(); // Determine the final size of the subsequence
    // If the first two elements are the same, reduce the size by one
    if (ans[0] == ans[1])
        finalSize--;

    cout << finalSize << "\n";
    return;
}

int main()
{

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
