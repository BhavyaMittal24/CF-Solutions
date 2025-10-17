
#include <bits/stdc++.h>
using namespace std;

void solve()
{

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > n || a[i] < 1)
        {
            cout << 0 << endl;
            return;
        }
    }
    if (n == 1)
    {
        cout << '2' << endl;
        return;
    }

    vector<int> diff;
    int delta = a[1] - a[0];

    vector<int> originalArray1(n);
    vector<int> originalArray2(n);

    vector<char> orientation1(n);
    vector<char> orientation2(n);

    if (delta == 1)
    {
        orientation1[0] = 'L';
    }
    else if (delta == -1)
    {
        orientation1[0] = 'R';
    }
    else
    {
        orientation1[0] = 'R';
        orientation2[0] = 'L';
    }

    for (int i = 1; i < n; i++)
    {
        int d = a[i] - a[i - 1];
        if (abs(d) > 1)
        {
            cout << 0 << endl;
            return;
        }

        diff.push_back(d);

        if (d == 1)
        {
            orientation1[i] = 'L';
            orientation2[i] = 'L';
        }
        else if (d == -1)
        {
            orientation1[i] = 'R';
            orientation2[i] = 'R';
        }
        else
        {
            orientation1[i] = orientation1[i - 1] == 'R' ? 'L' : 'R';
            orientation2[i] = orientation2[i - 1] == 'R' ? 'L' : 'R';
        }

        if (i > 1)
        {
            if (abs(d - diff[i - 2]) > 1)
            {
                cout << 0 << endl;
                return;
            }
        }
    }

    int seen1 = 1;
    int seen2 = 1;
    for (int i = 1; i < n; i++)
    {
        if (orientation1[i] == 'R')
            seen1++;
        if (orientation2[i] == 'R')
            seen2++;
    }

    originalArray1[0] = seen1;
    originalArray2[0] = seen2;

    bool isSame1 = a[0] == seen1 ? true : false;
    bool isSame2 = a[0] == seen2 ? true : false;
    for (int i = 1; i < n; i++)
    {
        char newSign = orientation1[i];
        char oldSign = orientation1[i - 1];

        if (newSign == oldSign)
        {
            if (newSign == 'R')
            {
                seen1--;
            }
            else
            {
                seen1++;
            }
        }
        originalArray1[i] = seen1;
        if (originalArray1[i] != a[i])
            isSame1 = false;
    }

    for (int i = 1; i < n; i++)
    {
        char newSign = orientation2[i];
        char oldSign = orientation2[i - 1];

        if (newSign == oldSign)
        {
            if (newSign == 'R')
            {
                seen2--;
            }
            else
            {
                seen2++;
            }
        }
        originalArray2[i] = seen2;
        if (originalArray2[i] != a[i])
            isSame2 = false;
    }

    //    for(int i=0;i<n;i++){
    //      cout << orientation1[i] << " ";
    //    }
    //     cout << endl;
    //     for(int i=0;i<n;i++){
    //       cout << orientation2[i] << " ";
    //     }

    int cnt = 0;

    // check original arrya same as constructed array by jut comparing the first element

    if (isSame1)
        cnt++;
    if (isSame2)
        cnt++;

    cout << cnt << endl;

    // for(int i=0;i<n;i++){
    //     cout << orientation1[i] << " ";
    // }

    // cout << endl;

    // for(int i=0;i<n;i++){
    //     cout << orientation2[i] << " ";
    // }

    // cout << endl;

    // for(int i=0;i<n;i++){
    //     cout << originalArray1[i] << " ";
    // }
    // cout << endl;
    // for(int i=0;i<n;i++){
    //     cout << originalArray2[i] << " ";
    // }
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

// 4
// 2 2 2 3
//  0 0 1
// L R L

// 2 1
// R