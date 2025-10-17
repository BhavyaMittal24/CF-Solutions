#include <bits/stdc++.h>
using namespace std;

// can also use a set to store the max and the min elements in an interval or in a sliding window
// *ms.begin()
// *ms.end()
// but complexity will be slightly higher
int main()
{
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    //_ _ _ _ _ _ _ _ _ _ _
    //    l           r

    //  for each r, we have the largest (most right 'l')
    // a[r] - [l] <= k, then all segments enclosed in side this will be also good.
    // counr all good subarrays

    int left = 0;
    int right = 0;
    long long cnt = 0;
    // maintain sets or deques for the min and max in the sliding window
    deque<int> mindq;
    deque<int> maxdq;
    for (; right < n; right++)
    {
        while (!mindq.empty() && a[right] <= a[mindq.back()])
            mindq.pop_back();
        mindq.push_back(right);

        while(!maxdq.empty() && a[right] >= a[maxdq.back()])
            maxdq.pop_back();
        maxdq.push_back(right);
        long long top = !maxdq.empty() ? a[maxdq.front()] : 0;
        long long bottom = !mindq.empty() ? a[mindq.front()] : 0;
        while (top - bottom > k)
        {
            if (!maxdq.empty() && maxdq.front() == left)
                maxdq.pop_front();
            if (!mindq.empty() && mindq.front() == left)
                mindq.pop_front();
            left++;
            top = !maxdq.empty() ? a[maxdq.front()] : 0;
            bottom = !mindq.empty() ? a[mindq.front()] : 0;
        }

        if (top - bottom <= k)
        {
            cnt += (right - left + 1);
        }
    }
    cout << cnt << endl;
    return 0;
}