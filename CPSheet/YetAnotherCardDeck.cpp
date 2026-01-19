#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> firstColorIndex(51,n+2);

    for(int i = 1; i <= n ; i ++){
        int color;
        cin >> color;
        // i -> index for the color
        firstColorIndex[color] = min(firstColorIndex[color], i);
    }

    for(int i = 1; i <= q; i ++){
        int queryColor ;
        cin >> queryColor;

        cout << firstColorIndex[queryColor] << " ";

        for(int color = 1; color <= 50 ; color++){
            if( color == queryColor) continue;

            if( firstColorIndex[color] < firstColorIndex[queryColor]) firstColorIndex[color] ++;
        }
        firstColorIndex[queryColor] = 1;
    }

    cout << "\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}