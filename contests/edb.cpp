#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    // return the vector with signs for 1 to n

    //
    vector<char> state(n, '+');
    string s;
    cin >> s;

    int i = 0;
    int j = n - 1;

    int i1 = 0;
    int j1 = n - 1;
    int k = 0;

    for (; k < m && i1 <= j1; k++)
    {
        if (s[k] == '2' && i <=j){
            state[i] = '?';
            state[j] = '?';
            i++;
            j--;
        }
        else if(s[k] == '2' && i > j){
            continue;
        }
        else if (s[k] == '0')
        {
            if (state[i-1] == '?')
            {
                state[i1] = '-';
                state[i] = '?';
                i++;
                i1++;
            }
            else {
                if(i <= j )state[i] = '-';
                state[i1] = '-';
                i++;
                i1 = i;
            }
            
        }
        // si = 1
        else
        {
            if (state[j-1] == '?')
            {
                state[j1] = '-';
                state[j] = '?';
                j--;
                j1--;
            }
            else {
                if(i<=j ) state[j] = '-';
                state[j1] = '-';
                j--;
                j1 = j;
            }
        }
    }

    for(int i=0;i<n;i++){
        cout << state[i];
    }
    cout << endl;
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