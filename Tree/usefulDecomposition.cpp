#include<bits/stdc++.h>
using namespace std;


int main(){

    int n;
    cin >> n;

    vector<vector<int>> adj(n+1);

    int cntGreaterThan2 = 0;
    for(int i = 0; i < n-1; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int root = 1;
    vector<int> leaves;
    for(int i = 1 ; i <= n ; i ++){
        if( adj[i].size() >=3) {
            cntGreaterThan2 ++;
            root = i;
        }

        if(adj[i].size() == 1) leaves.push_back(i);
    }

    if(cntGreaterThan2 > 1) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    cout << leaves.size() << endl;
    for(int i = 0 ; i < leaves.size() ; i ++){
        cout << root << " " << leaves[i] << endl;
    }

    return 0;
}