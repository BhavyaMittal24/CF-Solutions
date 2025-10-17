// find cost of each window to make elements equal of size k
#include <bits/stdc++.h>
using namespace std;

long long leftSum = 0;
long long rightSum = 0;


void balance(multiset<int> &left, multiset<int> &right)
{
    if (!left.empty() && left.size() > right.size() + 1)
    {
        leftSum -= *left.rbegin();
        rightSum += *left.rbegin();
        right.insert(*left.rbegin());
        left.erase(left.find(*left.rbegin()));
    }
    if (!right.empty() && left.size() < right.size())
    {
        rightSum -= *right.begin();
        leftSum += *right.begin();
        left.insert(*right.begin());
        right.erase(right.find(*right.begin()));
    }
}

int main()
{

    multiset<int> left;
    multiset<int> right;
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    int rightSize = k/2;
    int leftSize = k - rightSize;
    vector<long long> ans;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (left.empty() || arr[i] <= *left.rbegin())
        {
            left.insert(arr[i]);
            leftSum += arr[i];
            balance(left, right);
        }
        else {
            right.insert(arr[i]);
            rightSum += arr[i];
            balance(left, right);
        }
        if (i >= k)
        {
         auto itLeft = left.find(arr[i-k]);
         auto itRight = right.find(arr[i-k]);
         if (itLeft != left.end())
         {
             left.erase(itLeft);
             leftSum -= arr[i - k];
             balance(left, right);
         }
         else if (itRight != right.end())
         {
             right.erase(itRight);
             rightSum -= arr[i - k];
             balance(left, right);
         }
        }
        if (i >= k - 1)
        {
            long long median = *left.rbegin();
            long long answer = 1ll * leftSize * median - leftSum + rightSum - 1ll *rightSize * median;
            ans.push_back(answer);

        }
    }
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}