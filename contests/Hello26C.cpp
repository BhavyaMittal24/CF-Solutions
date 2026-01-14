#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--)
    {

        int n, m, k;

        cin >> n >> m >> k;

        // for x bases : I can take l + max(r,l) - 1  + r time
        int low = 1;
        int high = n;
        // can i have mid bases in some time t
        // tine taken for  mid bases <= m

        int maxBases = 1;
        while (low <= high)
        {
            int mid = (high + low) / 2;

            int minTime = INT_MAX;
            // find the min time across all l,r for a single mid
            for (int left = 0; left <= mid - 1; left++)
            {
                int right = mid - left - 1;
                if (k <= left || right + k > n)
                    continue;
                int timeTaken = max(left, right) - 1 + left + right;
                minTime = min(minTime, timeTaken);
            }

            if (mid == 1)
                minTime = 0;

            if (minTime <= m)
            {
                maxBases = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }

        cout << maxBases << "\n";
    }

    return 0;
}