// n players , m cards

//             card no
// player  1   2   3 ............... m

//     p1  a1 a2  a3
//     p2  b1 b2 b3
//     p3

#include <bits/stdc++.h>
using namespace std;

// each column can be solved independently for each card number i p1, p2, ... pn : find the answer : sort it and then get the answer

long long findModValue(vector<int> &values)
{

    sort(values.begin(), values.end());

    int n = values.size();
    vector<long long> suffix(n + 1);

    suffix[n] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        suffix[i] += (suffix[i + 1] + 1ll * values[i]);
    }

    long long ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans += (suffix[i] - 1ll * (n - i) * values[i]);
    }

    return ans;
}

void solve()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    vector<vector<int>> playerValuesPerCard(m + 1);
    for (int i = 1; i <= n; i++)
    {

        // i : player number
        for (int j = 1; j <= m; j++)
        {
            // j : card number
            // for each i : you get m cards
            int x;
            cin >> x;
            playerValuesPerCard[j].push_back(x);
        }
    }

    // m+1 cards : for each card nummber : the number for all players
    // jth card : p1,p2, .... pn

    long long ans = 0;
    // for each card number i : 1 to m find the value for the mod (ai - bi) for all the pairs
    for (int i = 1; i <= m; i++)
    {

        // pass the n values for all the players
        vector<int> valuesForCardI = playerValuesPerCard[i];
        ans += findModValue(valuesForCardI);
    }

    cout << ans << "\n";
}

int main()
{

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}