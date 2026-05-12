// find the min distinct elements in a window of size d

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k, d;
    cin >> n >> k >> d;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    map<int,int> ms;
    int minDist = n + 1;
    for (int i = 0; i < n; i++)
    {
        ms[a[i]]++;
        if (i >= d)
        {   ms[a[i-d]]--;
            if(ms[a[i-d]] == 0) ms.erase(a[i - d]);
        }
        if (i >= d - 1)
        {
            minDist = min(minDist, int(ms.size()));
        }
    }
    cout << minDist << endl;
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