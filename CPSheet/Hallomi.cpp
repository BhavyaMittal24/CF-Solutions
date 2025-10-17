#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    if (k >= 2){
        cout << "YES" << endl;
        return;    }

    if (k == 1)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;

}
int main()
{
    int t;
    cin >> t;
    while (t--){
    solve();
    }
    
    return 0;
}