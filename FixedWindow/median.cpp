// find the median of each subarray of size k in an array
// fixed size window of size k
#include <bits/stdc++.h>
using namespace std;

// ms.erase(mp.find(key))
// ms.extract(key)

// removes only one occurrence in the ms
// left     right
// _______ ______

// if (left.size() -1 > right.size())
// or
// left.size() < right.size()

void balance(multiset<int> &left, multiset<int> &right)
{
    if(left.size() - 1 > right.size())
    {
        int element = *left.rbegin();
        left.erase(left.find(element));
        right.insert(element);
    }
    if(left.size() < right.size())
    {
        int element = *right.begin();
        right.erase(right.find(element));
        left.insert(element);
    }
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    multiset<int> left;
    multiset<int> right;

    vector<double> ans;
    for (int i = 0; i < n; i++)
    {
        if (left.empty() || arr[i] <= *left.rbegin())
            left.insert(arr[i]);
        else
            right.insert(arr[i]);
        balance(left, right);

        if (i >= k)
        {
            auto it = left.find(arr[i-k]);
            if (it != left.end())
            {
                left.erase(it);
            }
            else
            {
                it = right.find(arr[i-k]);
                if (it != right.end())
                {
                    right.erase(it);
                }
            }
            balance(left, right);
        }
        if (i >= k - 1)
        {
            ans.push_back(*left.rbegin());
            // if (k % 2 == 1)
            // {
            // }
            // else
            // {
            //     int x = *left.rbegin();
            //     int y = *right.begin();
            //     double median = (1.0 * x + 1.0 * y) / 2.0;
            //     ans.push_back(median);
            // }
        }
    }
    for (auto it : ans)
    {
        cout << it << " ";
    }
    // cout << "ans.size() = " << ans.size() << endl;
}