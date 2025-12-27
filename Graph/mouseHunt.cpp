#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    vector<int> c(n+1, 0);
    vector<int> a(n+1, 0);

    long long cost = 0;

    vector<int> vis(n+1, 0);

    vector<vector<int>> adj(n+1);
    for(int i = 1 ; i <= n ; i++){
        cin >> c[i];
    }

    for(int i = 1; i <= n ; i ++){
        cin >> a[i];
        if(a[i] == i) {
            cost += c[i];
            vis[i] = 1;
        }
            // i -> ai
        adj[i].push_back(a[i]);
    }

    for(int i = 1; i <= n ; i ++){
        // cout << i << " " ;
        int minVal = 1e5;
        if( vis[i] == 0){
            int node = i;
            int nextNode = adj[node][0];

            //cout << node << " " << nextNode << " ";
            if( (adj[nextNode][0] == node) && (!vis[node]) && !vis[nextNode]){
                minVal = min(minVal, c[node]);
                minVal = min(minVal, c[nextNode]);
                vis[node] = 1;
                vis[nextNode] = 1;
                cost += minVal;
            }
            vis[node]  = 1;
        }
    }

    cout << cost << endl;
    return 0;
}