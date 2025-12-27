#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;

    vector<int> quality(n + 1, 0);

    for (int i = 1; i <= n; i++)
        cin >> quality[i];

    int m;
    cin >> m;

    vector<int> notRoot(n + 1, 0);

    vector<int> minWtParent(n+1, 1e9);
    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        // u is the parent of v
        minWtParent[v] = min(minWtParent[v], w);

        notRoot[v] = 1;
    }

    int root = 0;

    int cntRoot = 0;
    for (int i = 1; i <= n; i++)
    {
        if (notRoot[i] == 0)
        {
            root = i;
            cntRoot ++;
        }
    }

  
    if(cntRoot > 1){
        cout << -1 << endl;
        return 0;
    }
    else{
        int ans = 0;
        for(int i = 1; i <= n; i ++){
            if( i != root) {
                ans += minWtParent[i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}