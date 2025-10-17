#include <bits/stdc++.h>
using namespace std;

void balance(multiset<long long> &left, multiset<long long> &right)
{
    if(!left.empty() && left.size() - 1 > right.size())
    {
        int element = *left.rbegin();
        left.erase(left.find(element));
        right.insert(element);
    }
    if(!right.empty() && left.size() < right.size())
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
    multiset<long long> left;
    multiset<long long> right;

    vector<long long> ans;
    for (int i = 0; i < n; i++)
    {
        // Add current element
        if (left.empty() || arr[i] <= *left.rbegin())
            left.insert(arr[i]);
        else
            right.insert(arr[i]);
        balance(left, right);

        if (i >= k)
        {
            // Remove the element that's going out of the window
            auto it = left.find(1ll*arr[i-k]);
            if (it != left.end())
            {
                left.erase(it);
            }
            else
            {
                it = right.find(1ll*arr[i-k]);
                if (it != right.end())
                {
                    right.erase(it);
                }
            }
            balance(left, right);
        }
        if (i >= k - 1)
        {
            if (!left.empty()) {
                ans.push_back(*left.rbegin());
            }
        }
    }
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}