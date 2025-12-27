#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    vector<vector<int>> adj(n+1);
    for(int i = 2 ; i <= n ; i ++){
        int parenti;
        cin >> parenti;
        // parenti ---> i
        adj[i].push_back(parenti);
        adj[parenti].push_back(i);
    }

    queue<int> q;
    vector<int> vis(n+1,0);

    int childrenBase = 0;

    int ans = 1;

    q.push(1);
    vis[1] = 1;

    while( !q.empty()){
        int qSize = q.size();
        ans = ans + (childrenBase % 2);

        while( qSize --){
            int node = q.front();
            q.pop();
            if(childrenBase) childrenBase --;
            childrenBase += adj[node].size();
            if(node != 1) childrenBase --;

            for(int x : adj[node]){
                if( !vis[x]){
                    q.push(x);
                    vis[x] = 1;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}