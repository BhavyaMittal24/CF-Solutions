#include<bits/stdc++.h>
using namespace std;

int N = 2e5+1;
vector<int> inCycle(N, 0);
vector<int> cyclicNodes;

bool dfs(int node, vector<int> &vis, vector<vector<int>> &adj, vector<int> &c){

    vis[node] = 2;

    //minVal = min(minVal, c[node]);

    for(int x : adj[node]){
        if( vis[x] == 0){
            if( dfs(x, vis, adj, c)) return true;
        }
        else if( vis[x] == 2) {
            if(inCycle[x] == 0){
                inCycle[x] = 1;
                cyclicNodes.push_back(x);
            }
            return true;
        }
    }

    vis[node] = 1;
    return false;
}

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

    vector<int> isMinConsidered(n+1, 0);

    for(int i = 1; i <= n ; i ++){
        cin >> a[i];
        if(a[i] == i) {
            cost += c[i];
            vis[i] = 2;
            inCycle[i] = 1;
            isMinConsidered[i] = 1;
        }
            // i -> ai
        adj[i].push_back(a[i]);
    }

    for(int i = 1; i <= n ; i ++){
        // cout << i << " " ;
       if( vis[i] == 0){
            bool a = dfs(i, vis, adj, c);
       }
    }


    for( auto node : cyclicNodes) cout << node << " ";
    cout << endl;
    for(auto node : cyclicNodes){

        //cout << node << " " << endl ;
        if(isMinConsidered[node]) continue;
        int minValue = c[node];
        isMinConsidered[node] = 1;
        int temp = a[node];
        while( temp != node){
            minValue = min(minValue, c[temp]);
            isMinConsidered[temp] = 1;
            temp = a[temp];
        }
        cost += minValue;
    }

    cout << cost << endl;
    return 0;
}