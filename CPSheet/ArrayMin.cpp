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

        int n;
        cin >> n;

        int b_len = n * (n - 1) / 2;
        vector<int> b(b_len);

        for (int i = 0; i < b_len; i++)
            cin >> b[i];

        sort(b.begin(), b.end());

        vector<int> a(n);

        int idx = 0;
        int cnt = 1;
        for (int i = 0; i < b_len; i++)
        {

            if (i == 0)
            {
                cnt = 1;
            }

            if (b[i] == b[i - 1])
            {
                cnt++;
            }
            else if (cnt == n - 1 - idx)
            {
                a[idx] = b[i - 1];
                idx++;
                cnt = 1;
            }
            else if (cnt > n - 1 - idx)
            {
                while (cnt != 0)
                {
                    cnt = cnt - (n - 1 - idx);
                    a[idx] = b[i - 1];
                    idx++;
                }
                cnt = 1;
            }
        }

        if( a[idx] != b[n-1] ) a[idx] = b[n-1];
        idx++; 

        int maxValue = b.back();
        cout << maxValue << " maxValue is " << "\n";
        for (int i = idx; i < n; i++)
        {
            a[idx] = maxValue;
        }

        for (auto x : a)
            cout << x << " ";

        cout << "\n";
    }

    return 0;
}