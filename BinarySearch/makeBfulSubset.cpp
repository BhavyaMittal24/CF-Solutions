// Problem beautiful arrays

#include <bits/stdc++.h>
using namespace std;

bool checkAtleastOneSubsetBful(int n, vector<int> &queries, int idx, vector<pair<int, int>> &subset)
{
    vector<int> a(n, 0);
    for (int i = 0; i <= idx; i++)
    {
        a[queries[i]] = 1;
    }
    vector<int> prefixSum(n, 0);
    prefixSum[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + a[i];
    }

    // go through all the m subsets
    for (int i = 0; i < subset.size(); i++)
    {
        int left = subset[i].first;
        int right = subset[i].second;
        int count1 = (left !=0) ? prefixSum[right] - prefixSum[left - 1] : prefixSum[right];
        if (count1 > (right - left + 1) / 2){
            return true;
        }
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        // array with 0
        // m,n <= 1e9
        int n;
        int m;
        cin >> n >> m;

        vector<pair<int, int>> subset(m);
        for (int i = 0; i < m; i++)
        {
            int l;
            int r;
            cin >> l >> r;
            subset[i] = {l-1, r-1};
        }
        // query : each query tells you the idx to make it 1. When you execute ith query it means 0-i are also executed
        int q;
        cin >> q;
        vector<int> queries(q);
        for (int i = 0; i < q; i++)
        {
            cin >> queries[i];
            queries[i]--; // converting to 0 based index
        }

        // find the minimum changes number after which atleast one subset becomes bful
        int low = 0;
        int high = q-1;
        int mid = 0;
        int ans = -1;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (checkAtleastOneSubsetBful(n, queries, mid, subset))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        ans = (ans != -1) ? ans + 1 : -1; // converting to 1 based index
        cout << ans << endl;
    }

    return 0;
}