#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int a = 0;
    int b = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a')
            a++;
        else
            b++;
    }

    if (a == b)
    {
        cout << "0" << endl;
        return;
    }
    else if (a == 0 || b == 0)
    {
        cout << -1 << endl;
        return;
    }

    int len = n + 1;
    // total elements = n = a+b;
    if (a > b)
    {
        int left = 0;
        int right = 0;

        int cnta = 0;
        int cntb = 0;
        while (left <= right && right < n)
        {
            if (s[right] == 'a')
                cnta++;
            else
                cntb++;

            while (cnta - cntb >= a - b && left <= right)
            {
                if (cnta - cntb == a - b && cntb < b && cnta < a)
                {
                    len = min(len, right - left + 1);
                }
                if (s[left] == 'a')
                    cnta--;
                else
                    cntb--;
                left++;
            }

            right++;
        }
    }
    else
    {
        int left = 0;
        int right = 0;

        int cnta = 0;
        int cntb = 0;
        while (left <= right && right < n)
        {
            if (s[right] == 'a')
                cnta++;
            else
                cntb++;

            while (cntb - cnta >= b - a && left <= right)
            {
                if (cntb - cnta == b - a && cntb < b && cnta < a)
                {
                    len = min(len, right - left + 1);
                }
                if (s[left] == 'a')
                    cnta--;
                else
                    cntb--;
                left++;
            }
            right++;
        }
    }
    if (len == n + 1)
        len = -1;
    cout << len << endl;
    return;
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