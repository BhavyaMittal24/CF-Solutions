
#include<bits/stdc++.h>
using namespace std;

void solve()
{

    int n, k;
    cin >> n >> k;

    // can escape from k cells

    // no of cells from where you cant escape
    int m = n * n - k;
    if (m == 1)
    {
        cout << "NO" << endl;
        return;
    }
    if (m == 0)
    {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << "D";
            }
            cout << endl;
        }
    }

    if (m >= 2)
    {
        cout << "YES" << endl;
        cout << "RL";
        m -= 2;
        for (int i = 2; i < n; i++)
        {
            if (m > 0)
            {
                cout << "L";
                m--;
            }
            else
            {
                cout << "U";
            }
        }
        cout << endl;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (m > 0)
                {
                    cout << 'U';
                    m--;
                }
                else
                {
                    cout << 'D';
                }
            }
            cout << endl;
        }
    }
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