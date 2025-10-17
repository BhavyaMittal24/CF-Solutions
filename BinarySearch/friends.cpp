#include <bits/stdc++.h>
using namespace std;

bool isPossibleToInvite(int x, vector<pair<int, int>> &bounds)
{
    // 1 2
    // 2 1
    // 1 1

    // count = 1
    // x = 2
    // a = 1
    // b = 2
    int count = 0;

    for (int i = 0; i < bounds.size(); i++)
    {
        int a = bounds[i].first;  // at most a friends are richer
        int b = bounds[i].second; // at most b friends are poorer
        if (x >= count + 1 && x - count -1 <= a && count <= b)
        {
            count++;
        }
    }
    return count >=x;
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> bounds(n);
    for (int i = 0; i < n; i++)
    {
        cin >> bounds[i].first >> bounds[i].second;
    }
    // for each test case
    // find the max number of friends
    // that can be onvited such that at most ai friends are rocher and bi friends are poorer
    // ith friends is ith rich

    // 1 2
    // 2 1
    // 1 1
    int low = 0;
    int high = n;
    int mid = 0;
    int ans = -1;
    // TTTTTTTTTTTFFFFFFFFFF
    // f(x) = if i can invite x friends <= x` T
    // else F
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (isPossibleToInvite(mid, bounds))
        {
            low = mid + 1;
            ans = mid;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << ans << endl; // print the max number of friends that can be invited
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